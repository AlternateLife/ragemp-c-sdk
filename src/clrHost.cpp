/*
 * File: clrHost.cpp
 * Author: MarkAtk
 * Date: 09.10.2018
 *
 * MIT License
 *
 * Copyright (c) 2018 Rage-MP-C-SDK
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "clrHost.h"

#include "clrPlugin.h"

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <stdlib.h>
#include <dlfcn.h>
#include <dirent.h>
#include <sys/stat.h>
#endif

#define RUNTIME_DIR_PATH "./dotnet/runtime/"
#define PLUGIN_DIR_PATH "./dotnet/plugins/"

#define PLUGIN_CLASS_NAME "RageMP.Net.PluginWrapper"

#ifdef _WIN32
#define LIST_SEPARATOR ";"
#else
#define LIST_SEPARATOR ":"
#endif

ClrHost::ClrHost() {
    _runtimeHost = nullptr;
    _domainId = 0;

    _coreClrLib = nullptr;
    _initializeCoreCLR = nullptr;
    _shutdownCoreCLR = nullptr;
    _createDelegate = nullptr;
}

ClrHost::~ClrHost() {
    unload();
}

bool ClrHost::load() {
    if (_coreClrLib == nullptr && loadCoreClr() == false) {
        return false;
    }

    if ((_runtimeHost == 0 || _domainId == 0) && createAppDomain() == false) {
        return false;
    }

    getPlugins();

    for (auto &plugin : _plugins) {
        MainMethod callback;
        if (getDelegate(plugin->filename(), "Main", (void **)&callback) == false) {
            continue;
        }

        plugin->setMainCallback(callback);

        std::cout << "[.NET] Plugin " << plugin->filename() << " loaded" << std::endl;
    }

    return true;
}

void ClrHost::unload() {
    for (auto &plugin : _plugins) {
        delete plugin;
    }

    _plugins.clear();

#ifdef _WIN32
    if (_runtimeHost == 0) {
        return;
    }

    if (_domainId != 0) {
        _runtimeHost->UnloadAppDomain(_domainId, true);

        _domainId = 0;
    }

    _runtimeHost->Stop();
    _runtimeHost->Release();

    _runtimeHost = 0;
#else


    if (_coreClrLib != nullptr) {
        dlclose(_coreClrLib);

        _coreClrLib = nullptr;
    }
#endif
}

std::vector<ClrPlugin *> ClrHost::plugins() const {
    return _plugins;
}

bool ClrHost::loadCoreClr() {
    std::string coreClrDllPath = getAbsolutePath(RUNTIME_DIR_PATH);

#ifdef _WIN32
    coreClrDllPath += "/coreclr.dll";

    HMODULE hModule = LoadLibraryEx(coreClrPath, NULL, 0);
    if (hModule == NULL) {
        std::cerr << "[.NET] Unable to find CoreCLR dll" << std::endl;

        return false;
    }

    // TODO: get new methods
    auto fnGetCLRRuntimeHost = (FnGetCLRRuntimeHost)::GetProcAddress(hModule, "GetCLRRuntimeHost");
    if (fnGetCLRRuntimeHost == NULL) {
        std::cerr << "[.NET] Runtime host function not found" << std::endl;

        return false;
    }

    auto result = fnGetCLRRuntimeHost(IID_ICLRRuntimeHost2, (IUnknown **)&_runtimeHost);
    if (FAILED(result)) {
        std::cerr << "[.NET] Failed to get runtime instance" << std::endl;

        return false;
    }

    result = _runtimeHost->SetStartupFlags(static_cast<STARTUP_FLAGS>(
            STARTUP_FLAGS::STARTUP_CONCURRENT_GC |
            STARTUP_FLAGS::STARTUP_SINGLE_APPDOMAIN |
            STARTUP_FLAGS::STARTUP_LOADER_OPTIMIZATION_SINGLE_DOMAIN
        )
    );

    if (FAILED(result)) {
        std::cerr << "[.NET] Failed to set runtime startup flags" << std::endl;

        return false;
    }

    result = _runtimeHost->Start();
    if (FAILED(result)) {
        std::cerr << "[.NET] Failed to start Core CLR host" << std::endl;

        return false;
    }
#else
#ifdef __APPLE__
    coreClrDllPath += "/libcoreclr.dylib";
#else
    coreClrDllPath += "/libcoreclr.so";
#endif

    void *coreClrLib = dlopen(coreClrDllPath.c_str(), RTLD_NOW | RTLD_LOCAL);
    if (coreClrLib == nullptr) {
        std::cerr << "[.NET] Unable to find CoreCLR dll: " << dlerror() << std::endl;

        return false;
    }

    _initializeCoreCLR = (coreclr_initialize_ptr)dlsym(coreClrLib, "coreclr_initialize");
    _shutdownCoreCLR = (coreclr_shutdown_2_ptr)dlsym(coreClrLib, "coreclr_shutdown_2");
    _createDelegate = (coreclr_create_delegate_ptr)dlsym(coreClrLib, "coreclr_create_delegate");

    if (_initializeCoreCLR == nullptr || _shutdownCoreCLR == nullptr || _createDelegate == nullptr) {
        std::cerr << "[.NET] Unable to find CoreCLR dll methods" << std::endl;

        return false;
    }
#endif

    return true;
}

bool ClrHost::createAppDomain() {
    std::string tpaList = "";

    for (auto &tpa : getTrustedAssemblies()) {
        tpaList += tpa;
        tpaList += LIST_SEPARATOR;
    }

    auto appPath = getAbsolutePath(PLUGIN_DIR_PATH);

    auto nativeDllPaths = appPath;
    nativeDllPaths += LIST_SEPARATOR;
    nativeDllPaths += getAbsolutePath(RUNTIME_DIR_PATH);

    auto rootDirectory = getAbsolutePath(".");

    const char *propertyKeys[] = {
        "TRUSTED_PLATFORM_ASSEMBLIES",
        "APP_PATHS",
        "APP_NI_PATHS",
        "NATIVE_DLL_SEARCH_DIRECTORIES",
        "System.GC.Server",
        "System.Globalization.Invariant",
    };

    const char *propertyValues[] = {
        tpaList.c_str(),
        appPath.c_str(),
        appPath.c_str(),
        nativeDllPaths.c_str(),
        "true",
        "true",
    };

    int result = _initializeCoreCLR(
        rootDirectory.c_str(), 
        "RageMP Host Domain", 
        sizeof(propertyKeys) / sizeof(propertyKeys[0]), 
        propertyKeys,
        propertyValues,
        &_runtimeHost,
        &_domainId
    );

    if (result < 0) {
        std::cerr << "[.NET] Unable to create app domain" << std::endl;

        return false;
    }

    return true;
}

void ClrHost::getPlugins() {
    std::string pluginDirectory = getAbsolutePath(PLUGIN_DIR_PATH);

#ifndef _WIN32
    auto directory = opendir(pluginDirectory.c_str());
    if (directory == nullptr) {
        std::cerr << "[.NET] Runtime directory not found" << std::endl;

        return;
    }

    struct dirent* entry;
#endif

    _plugins.clear();

#ifdef _WIN32
    std::wstring searchPath = pluginDirectory;
    searchPath += "*.dll";

    WIN32_FIND_DATA findData;
    HANDLE fileHandle = FindFirstFile(searchPath.c_str(), &findData);

    if (fileHandle == INVALID_HANDLE_VALUE) {
        return;
    }

    do {
        std::string filePath = pluginDirPath;
        filePath += findData.cFileName;

        std::string filename = getFilenameWithoutExtension(findData.cFileName);
#else
    while ((entry = readdir(directory)) != nullptr) {
        switch (entry->d_type) {
            case DT_REG:
                break;

            // Handle symlinks and file systems that do not support d_type
            case DT_LNK:
            case DT_UNKNOWN:
                {
                    std::string fullFilename;

                    fullFilename.append(pluginDirectory);
                    fullFilename.append(entry->d_name);

                    struct stat sb;
                    if (stat(fullFilename.c_str(), &sb) == -1) {
                        continue;
                    }

                    if (!S_ISREG(sb.st_mode)) {
                        continue;
                    }
                }
                break;

            default:
                continue;
        }

        std::string filename(entry->d_name);
        std::string filePath(pluginDirectory);
        filePath += filename;

        // Check if the extension matches the one we are looking for
        int extPos = filename.length() - 4;
        if (extPos <= 0 || filename.compare(extPos, 4, ".dll") != 0) {
            continue;
        }

        filename = filename.substr(0, extPos);
#endif

        auto plugin = new ClrPlugin(filename, filePath);

        _plugins.push_back(plugin);
#ifdef _WIN32
    } while (FindNextFile(fileHandle, &findData));

    FindClose(fileHandle);
#else
    }

    closedir(directory);
#endif
}

std::set<std::string> ClrHost::getTrustedAssemblies() {
    std::set<std::string> assemblies;

    const char * const tpaExtensions[] = { ".ni.dll", ".dll", ".ni.exe", ".exe", ".winmd" };

    std::string runtimeDirectory = getAbsolutePath(RUNTIME_DIR_PATH);

#ifndef _WIN32
    auto directory = opendir(runtimeDirectory.c_str());
    if (directory == nullptr) {
        std::cerr << "[.NET] Runtime directory not found" << std::endl;

        return assemblies;
    }

    struct dirent* entry;
#endif

    for (int extIndex = 0; extIndex < sizeof(tpaExtensions) / sizeof(tpaExtensions[0]); extIndex++) {
        const char* ext = tpaExtensions[extIndex];
        int extLength = strlen(ext);

#ifdef _WIN32
        wchar_t searchPath[MAX_PATH];
        wcscpy_s(searchPath, MAX_PATH, rootPath);
        wcscat_s(searchPath, MAX_PATH, L"/");
        wcscat_s(searchPath, MAX_PATH, L"" RUNTIME_DIR_PATH);
        wcscat_s(searchPath, MAX_PATH, extensions[i]);

        WIN32_FIND_DATAW findData;
        HANDLE fileHandle = FindFirstFileW(searchPath, &findData);

        if (fileHandle == INVALID_HANDLE_VALUE) {
            continue;
        }

        do {
            // get file path
            wchar_t filePath[MAX_PATH];
            wcscpy_s(filePath, MAX_PATH, rootPath);
            wcscat_s(filePath, MAX_PATH, L"/");
            wcscat_s(filePath, MAX_PATH, L"" RUNTIME_DIR_PATH);
            wcscat_s(filePath, MAX_PATH, findData.cFileName);

            if (wcslen(filePath) + 3 + wcslen(assemblies) >= assemblyCount) {
                assemblyCount *= 2;

                auto newAssemblies = new wchar_t[assemblyCount];
                wcscpy_s(newAssemblies, assemblyCount, assemblies);

                free(assemblies);

                assemblies = newAssemblies;
            }

            wcscat_s(assemblies, assemblyCount, filePath);
            wcscat_s(assemblies, assemblyCount, L";");
        } while (FindNextFileW(fileHandle, &findData));

        FindClose(fileHandle);
#else
        while ((entry = readdir(directory)) != nullptr) {
            switch (entry->d_type) {
                case DT_REG:
                    break;

                // Handle symlinks and file systems that do not support d_type
                case DT_LNK:
                case DT_UNKNOWN:
                    {
                        std::string fullFilename;

                        fullFilename.append(runtimeDirectory);
                        fullFilename.append("/");
                        fullFilename.append(entry->d_name);

                        struct stat sb;
                        if (stat(fullFilename.c_str(), &sb) == -1) {
                            continue;
                        }

                        if (!S_ISREG(sb.st_mode)) {
                            continue;
                        }
                    }
                    break;

                default:
                    continue;
            }

            std::string filename(entry->d_name);

            // Check if the extension matches the one we are looking for
            int extPos = filename.length() - extLength;
            if (extPos <= 0 || filename.compare(extPos, extLength, ext) != 0) {
                continue;
            }

            std::string filenameWithoutExt(filename.substr(0, extPos));

            // Ensure assemblies are unique in the list
            if (assemblies.find(filenameWithoutExt) != assemblies.end()) {
                continue;
            }

            assemblies.insert(filenameWithoutExt);
        }

        // rewind directory to search for next extension
        rewinddir(directory);
#endif
    }

#ifndef _WIN32
    closedir(directory);
#endif

    return assemblies;
}

bool ClrHost::getDelegate(std::string filename, std::string methodName, void **callback) {
    if (_runtimeHost == 0 || _domainId == 0) {
        std::cerr << "[.NET] Core CLR host not loaded" << std::endl;

        return false;
    }

    int result = _createDelegate(_runtimeHost, _domainId, filename.c_str(), PLUGIN_CLASS_NAME, methodName.c_str(), callback);
    if (result < 0) {
        std::cerr << "[.NET] Unable to get '" << methodName << "' from '" << filename << "'" << std::endl;

        return false;
    }

    return true;
}

std::string ClrHost::getAbsolutePath(std::string relativePath) {
#ifdef _WIN32
    char absolutePath[MAX_PATH];
    GetFullPathName(relativePath.c_str(), MAX_PATH, absolutePath, NULL);
#else
    char absolutePath[PATH_MAX];

    if (realpath(relativePath.c_str(), absolutePath) == nullptr) {
        // no absolute path found
        absolutePath[0] = '\0';
    }
#endif

    return std::string(absolutePath);
}

std::string ClrHost::getFilenameWithoutExtension(std::string &filename) {
    auto pos = filename.rfind(".");
    if (pos == std::string::npos) {
        return filename;
    }

    return filename.substr(0, pos);
}

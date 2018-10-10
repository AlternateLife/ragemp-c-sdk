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

#define RUNTIME_DIR_PATH "./dotnet/runtime/"
#define PLUGIN_DIR_PATH "./dotnet/plugins/"

#define PLUGIN_CLASS_NAME L"RageMP.Net.PluginWrapper"

ClrHost::ClrHost() {
    _runtimeHost = 0;
    _domainId = 0;
}

ClrHost::~ClrHost() {
    unload();
}

bool ClrHost::load() {
    if (_runtimeHost == 0 && getRuntime() == false) {
        return false;
    }

    if (_domainId == 0 && createAppDomain() == false) {
        return false;
    }

    getPlugins();

    for (auto &plugin : _plugins) {
        MainMethod callback;
        if (getDelegate(plugin->filename().c_str(), L"Main", (void **)&callback) == false) {
            continue;
        }

        plugin->setMainCallback(callback);

        std::wcout << "[.NET] Plugin " << plugin->filename() << " loaded" << std::endl;
    }

    return true;
}

void ClrHost::unload() {
    for (auto &plugin : _plugins) {
        delete plugin;
    }

    _plugins.clear();

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
}

std::vector<ClrPlugin *> ClrHost::plugins() const {
    return _plugins;
}

bool ClrHost::getRuntime() {
    char *coreClrPath = new char[MAX_PATH];
    strcpy_s(coreClrPath, MAX_PATH, RUNTIME_DIR_PATH);
    strcat_s(coreClrPath, MAX_PATH, "coreclr.dll");

    HMODULE hModule = LoadLibraryEx(coreClrPath, NULL, 0);
    if (hModule == NULL) {
        std::cerr << "[.NET] Unable to find CoreCLR dll" << std::endl;

        return false;
    }

    // get runtime host
    auto fnGetCLRRuntimeHost = (FnGetCLRRuntimeHost)::GetProcAddress(hModule, "GetCLRRuntimeHost");
    if (fnGetCLRRuntimeHost == NULL) {
        std::cerr << "[.NET] Runtime host function not found" << std::endl;

        return false;
    }

    HRESULT result = fnGetCLRRuntimeHost(IID_ICLRRuntimeHost2, (IUnknown **)&_runtimeHost);
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

    return true;
}

bool ClrHost::createAppDomain() {
    DWORD appDomainFlags = APPDOMAIN_ENABLE_PLATFORM_SPECIFIC_APPS | APPDOMAIN_ENABLE_PINVOKE_AND_CLASSIC_COMINTEROP |
            APPDOMAIN_DISABLE_TRANSPARENCY_ENFORCEMENT;

    wchar_t *trustedAssemblies = getTrustedAssemblies();

    wchar_t appPaths[MAX_PATH];
    GetFullPathNameW(L"" PLUGIN_DIR_PATH, MAX_PATH, appPaths, NULL);

    wchar_t appNiPaths[MAX_PATH];
    wcscpy_s(appNiPaths, MAX_PATH, appPaths);

    wchar_t nativeDllPaths[2 * MAX_PATH];
    wcscpy_s(nativeDllPaths, 2 * MAX_PATH, L"" PLUGIN_DIR_PATH);
    wcscat_s(nativeDllPaths, 2 * MAX_PATH, L";");
    wcscat_s(nativeDllPaths, 2 * MAX_PATH, L"" RUNTIME_DIR_PATH);

    wchar_t platformResourceRoots[MAX_PATH];
    wcscpy_s(platformResourceRoots, MAX_PATH, appPaths);

    wchar_t *appDomainCompatSwitch = L"UseLatestBehaviorWhenTFMNotSpecified";

    const wchar_t *propertyKeys[] = {
        L"TRUSTED_PLATFORM_ASSEMBLIES",
        L"APP_PATHS",
        L"APP_NI_PATHS",
        L"NATIVE_DLL_SEARCH_DIRECTORIES",
        L"PLATFORM_RESOURCE_ROOTS",
        L"AppDomainCompatSwitch"
    };

    const wchar_t *propertyValues[] = {
        trustedAssemblies,
        appPaths,
        appNiPaths,
        nativeDllPaths,
        platformResourceRoots,
        appDomainCompatSwitch
    };

    HRESULT result = _runtimeHost->CreateAppDomainWithManager(
        L"RageMP Host Domain",
        appDomainFlags,
        NULL,
        NULL,
        sizeof(propertyKeys) / sizeof(wchar_t *),
        propertyKeys,
        propertyValues,
        &_domainId
    );

    if (FAILED(result)) {
        std::cerr << "[.NET] Unable to create app domain" << std::endl;

        return false;
    }

    return true;
}

wchar_t *ClrHost::getTrustedAssemblies() {
    size_t assemblyCount = 100 * MAX_PATH;
    auto assemblies = new wchar_t[assemblyCount];

    wcscpy_s(assemblies, assemblyCount, L"");

    wchar_t rootPath[MAX_PATH];
    GetFullPathNameW(L".", MAX_PATH, rootPath, NULL);

    wchar_t *extensions[] = { L"*.dll", L"*.exe", L".winmd" };

    for (int i = 0; i < _countof(extensions); i++) {
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
    }

    return assemblies;
}

void ClrHost::getPlugins() {
    _plugins.clear();

    wchar_t rootPath[MAX_PATH];
    GetFullPathNameW(L".", MAX_PATH, rootPath, NULL);

    std::wstring pluginDirPath = rootPath;
    pluginDirPath += L"/";
    pluginDirPath += L"" PLUGIN_DIR_PATH;

    std::wstring searchPath = pluginDirPath;
    searchPath += L"*.dll";

    WIN32_FIND_DATAW findData;
    HANDLE fileHandle = FindFirstFileW(searchPath.c_str(), &findData);

    if (fileHandle == INVALID_HANDLE_VALUE) {
        return;
    }

    do {
        std::wstring filePath = pluginDirPath;
        filePath += findData.cFileName;

        std::wstring filename = getFilenameWithoutExtension(findData.cFileName);

        auto plugin = new ClrPlugin(filename, filePath);

        _plugins.push_back(plugin);
    } while (FindNextFileW(fileHandle, &findData));

    FindClose(fileHandle);
}

bool ClrHost::getDelegate(const wchar_t *filename, wchar_t *methodName, void **callback) {
    if (_runtimeHost == 0 || _domainId == 0) {
        std::cerr << "[.NET] Core CLR host not loaded" << std::endl;

        return false;
    }

    HRESULT result = _runtimeHost->CreateDelegate(_domainId, filename, PLUGIN_CLASS_NAME, methodName, (INT_PTR *)callback);
    if (FAILED(result)) {
        std::wcerr << "[.NET] Unable to get '" << methodName << "' from '" << filename << "'" << std::endl;

        return false;
    }

    return true;
}

std::wstring ClrHost::getFilenameWithoutExtension(wchar_t *filename) {
    std::wstring name(filename);
    size_t pos = name.rfind(L".");
    if (pos == std::wstring::npos) {
        return name;
    }

    return name.substr(0, pos);
}

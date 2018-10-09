/*
 * File: rage.cpp
 * Author: MarkAtk
 * Date: 08.10.2018
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

#include "rage.h"

#include <ragemp-cppsdk/rage.hpp>
#include <coreclr/mscoree.h>

#include <stdio.h>

#include "eventHandler.h"
#include "multiplayer.h"
#include "plugin.h"

typedef void (STDMETHODCALLTYPE MainMethodFp)(LPWSTR* args);

wchar_t *getTrustedPlatformAssemblies() {
    int tpaSize = 100 * MAX_PATH;
    wchar_t *assemblies = new wchar_t[tpaSize];

    wcscpy_s(assemblies, tpaSize, L"");

    wchar_t rootPath[MAX_PATH];
    GetFullPathNameW(L".", MAX_PATH, rootPath, NULL);

    wchar_t *tpaExtensions[] = { L"*.dll", L"*.exe", L"*.winmd" };

    for (int i = 0; i < _countof(tpaExtensions); i++) {
        wchar_t searchPath[MAX_PATH];
        wcscpy_s(searchPath, MAX_PATH, rootPath);
        wcscat_s(searchPath, MAX_PATH, L"\\bridge\\runtime\\");
        wcscat_s(searchPath, MAX_PATH, tpaExtensions[i]);

        WIN32_FIND_DATAW findData;
        HANDLE fileHandle = FindFirstFileW(searchPath, &findData);

        if (fileHandle == INVALID_HANDLE_VALUE) {
            continue;
        }

        do {
            // get full path
            wchar_t fullPath[MAX_PATH];
            wcscpy_s(fullPath, MAX_PATH, rootPath);
            wcscat_s(fullPath, MAX_PATH, L"\\bridge\\runtime\\");
            wcscat_s(fullPath, MAX_PATH, findData.cFileName);

            if (wcslen(fullPath) + (3) + wcslen(assemblies) >= tpaSize) {
                // extend tpa list size
                tpaSize *= 2;
                wchar_t *newAssemblies = new wchar_t[tpaSize];
                wcscpy_s(newAssemblies, tpaSize, assemblies);
                assemblies = newAssemblies;
            }

            wcscat_s(assemblies, tpaSize, fullPath);
            wcscat_s(assemblies, tpaSize, L";");
        } while (FindNextFileW(fileHandle, &findData));

        FindClose(fileHandle);
    }

    return assemblies;
}

void loadCoreClrRuntime(EventHandler *eventHandler) {
    printf("Loading CoreCLR...\n");

    // get core clr dll
    HMODULE coreClrModule = LoadLibraryEx("./bridge/runtime/coreclr.dll", NULL, 0);
    if (coreClrModule == NULL) {
        printf("CoreCLR not found\n");

        return;
    }

    // get runtime host
    ICLRRuntimeHost2 *runtimeHost;

    FnGetCLRRuntimeHost pfnGetCLRRuntimeHost = (FnGetCLRRuntimeHost)::GetProcAddress(coreClrModule, "GetCLRRuntimeHost");
    if (pfnGetCLRRuntimeHost == NULL) {
        printf("Runtime host entry not found\n");

        return;
    }

    HRESULT hr = pfnGetCLRRuntimeHost(IID_ICLRRuntimeHost2, (IUnknown **)&runtimeHost);
    if (FAILED(hr)) {
        printf("Failed to get runtime host instance\n");

        return;
    }

    // setup startup flags
    hr = runtimeHost->SetStartupFlags(static_cast<STARTUP_FLAGS>(
            STARTUP_FLAGS::STARTUP_CONCURRENT_GC |
            STARTUP_FLAGS::STARTUP_SINGLE_APPDOMAIN |
            STARTUP_FLAGS::STARTUP_LOADER_OPTIMIZATION_SINGLE_DOMAIN
        )
    );

    if (FAILED(hr)) {
        printf("Failed to set start up flags\n");

        return;
    }

    // start host environment
    hr = runtimeHost->Start();
    if (FAILED(hr)) {
        printf("Failed to start host: %x\n", hr);

        return;
    }

    printf("Runtime started\n");

    // prepare app domain
    int appDomainFlags = APPDOMAIN_ENABLE_PLATFORM_SPECIFIC_APPS | APPDOMAIN_ENABLE_PINVOKE_AND_CLASSIC_COMINTEROP | APPDOMAIN_DISABLE_TRANSPARENCY_ENFORCEMENT;

    wchar_t *trustedAssemblies = getTrustedPlatformAssemblies();

    wchar_t appPaths[50 * MAX_PATH];
    GetFullPathNameW(L".\\test\\", 50 * MAX_PATH, appPaths, NULL);

    wchar_t appNiPaths[50 * MAX_PATH];
    wcscpy_s(appNiPaths, 50 * MAX_PATH, appPaths);

    wchar_t nativeDllPaths[50 * MAX_PATH];
    wcscpy_s(nativeDllPaths, 50 * MAX_PATH, L".\\test\\;.\\bridge\\runtime\\");

    wchar_t platformResourceRoots[50 * MAX_PATH];
    wcscpy_s(platformResourceRoots, 50 * MAX_PATH, appPaths);

    wchar_t* appDomainCompatSwitch = L"UseLatestBehaviorWhenTFMNotSpecified";

    // create app domain
    DWORD domainId;

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

    printf("Creating app domain...");

    hr = runtimeHost->CreateAppDomainWithManager(
        L"RageMP Host Domain",
        appDomainFlags,
        NULL,
        NULL,
        sizeof(propertyKeys) / sizeof(wchar_t *),
        propertyKeys,
        propertyValues,
        &domainId
    );

    if (FAILED(hr)) {
        printf("Unable to create app domain: %x\n", hr);

        return;
    }

    printf("App domain %d created\n", domainId);

//    TickMethod *tickDelegate = NULL;
//    hr = runtimeHost->CreateDelegate(domainId, L"RageMP-Wrapper", L"AlternateLife.PluginWrapper", L"OnTick", (INT_PTR *)&tickDelegate);
//    if (FAILED(hr)) {
//        printf("Unable to find tick delegate\n");
//
//        return;
//    }
//
//    eventHandler->setTickDelegate(tickDelegate);
//
//    PlayerJoinMethod *playerJoinDelegate = NULL;
//    hr = runtimeHost->CreateDelegate(domainId, L"RageMP-Wrapper", L"AlternateLife.PluginWrapper", L"OnPlayerJoin", (INT_PTR *)&playerJoinDelegate);
//    if (FAILED(hr)) {
//        printf("Unable to find player join delegate\n");
//
//        return;
//    }
//
//    eventHandler->setPlayerJoinDelegate(playerJoinDelegate);

    void *pfnDelegate = NULL;
    hr = runtimeHost->CreateDelegate(
        domainId,
        L"RageMP-Wrapper",
        L"AlternateLife.PluginWrapper",
        L"Main",
        (INT_PTR *)&pfnDelegate
    );

    if (FAILED(hr)) {
        printf("Unable to find delegate method\n");

        return;
    }

    printf("Calling delegate method...");

    ((MainMethodFp *)pfnDelegate)(NULL);

    printf("Ok\n");

    // cleanup
    /*runtimeHost->UnloadAppDomain(domainId, true);
    runtimeHost->Stop();
    runtimeHost->Release();*/

    printf("Cleaned up runtime host\n");
}

RAGE_API rage::IPlugin *InitializePlugin(rage::IMultiplayer *mp) {
    EventHandler *eventHandler = new EventHandler();
    mp->AddEventHandler(eventHandler);

    loadCoreClrRuntime(eventHandler);

    plugin_t *t = newPlugin();
    rage::IPlugin *plugin = static_cast<rage::IPlugin *>(t->obj);

    return plugin;
}

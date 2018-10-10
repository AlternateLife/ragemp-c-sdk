/*
 * File: clrHost.h
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

#pragma once

#include <coreclr/mscoree.h>

#include <vector>

class ClrPlugin;

class ClrHost {
private:
    ICLRRuntimeHost2 *_runtimeHost;
    DWORD _domainId;

    std::vector<ClrPlugin *> _plugins;

public:
    ClrHost();
    virtual ~ClrHost();

    bool load();
    void unload();

    std::vector<ClrPlugin *> plugins() const;

private:
    bool getRuntime();
    bool createAppDomain();
    wchar_t *getTrustedAssemblies();

    void getPlugins();
    bool getDelegate(const wchar_t *filename, wchar_t *methodName, void **callback);

    std::wstring getFilenameWithoutExtension(wchar_t *filename);
};

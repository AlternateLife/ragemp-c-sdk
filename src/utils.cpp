/*
 * File: utils.cpp
 * Author: MarkAtk
 * Date: 14.10.2018
 *
 * MIT License
 *
 * Copyright (c) 2018 RageMP-CLR-Host
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

#include "utils.h"

#include <iostream>

std::vector<std::pair<uint32_t, uint32_t>> getUintPairFromArrays(uint32_t *keys, uint32_t *values, size_t count) {
    std::vector<std::pair<uint32_t, uint32_t>> list(count);

    for (int i = 0; i < count; i++) {
        list.emplace_back(keys[i], values[i]);
    }

    return list;
}

const char *createCopyFromString(const std::string &str) {
    auto out = new char[str.length() + 1];

    strcpy(out, str.c_str());

    return out;
}

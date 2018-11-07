/*
 * File: utils.h
 * Author: MarkAtk
 * Date: 11.10.2018
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

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#endif
#include <ragemp-cppsdk/rage.hpp>
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <vector>

template<class T>
std::vector<T> getVectorFromArray(T *arr, size_t count) {
    std::vector<T> list(arr, arr + count);

    return list;
}

template<class T>
void getArrayFromVector(std::vector<T> list, T **arr, size_t *count) {
    auto array = new T[list.size()];
    *count = (uint32_t)list.size();

    for (int i = 0; i < list.size(); i++) {
        array[i] = list[i];
    }

    *arr = array;
}

template<class T, class U>
std::map<T, U> getMapFromArrays(T *keys, U *values, size_t count) {
    std::map<T, U> map;

    for (int i = 0; i < count; i++) {
        map.emplace(keys[i], values[i]);
    }

    return map;
}

template<class T>
T *copyStruct(T &in) {
    T* out = new T;
    memcpy_s((void *)out, sizeof(T), &in, sizeof(T));

    return out;
}

std::vector<std::pair<uint32_t, uint32_t>> getUintPairFromArrays(uint32_t *keys, uint32_t *values, size_t count);

const char *createCopyFromString(const std::string &str);

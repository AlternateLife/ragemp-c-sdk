/*
 * File: memory.cpp
 * Author: MarkAtk
 * Date: 09.11.2018
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

#include "memory.h"

void FreeTime(rage::time_t *time) {
    delete time;
}

void FreeRGBA(rage::rgba_t *color) {
    delete color;
}

void FreeRGB(rage::rgb_t *color) {
    delete color;
}

void FreeVector3(rage::vector3 *vector3) {
    delete vector3;
}

void FreeQuat(rage::quat_t *quat) {
    delete quat;
}

void FreeVector2(rage::vector2 *vector2) {
    delete vector2;
}

void FreeClothData(rage::clothData_t *cloth) {
    delete cloth;
}

void FreeHeadBlend(rage::headBlend_t *headBlend) {
    delete headBlend;
}

void FreePropData(rage::propData_t *prop) {
    delete prop;
}

void FreeArg(rage::arg_t *argument) {
    delete argument;
}

void FreeArgs(rage::args_t *arguments) {
    delete arguments;
}

void FreePaintInfo(rage::paintInfo_t *paintInfo) {
    delete paintInfo;
}

void FreeHeadOverlay(rage::headOverlay_t *headOverlay) {
    delete headOverlay;
}

void FreeString(char *string) {
    delete[] string;
}

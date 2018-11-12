/*
 * File: memory.h
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

#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#endif
#include <ragemp-cppsdk/rage.hpp>
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#ifdef __cplusplus
extern "C" {
#endif

RAGE_API void FreeTime(rage::time_t *time);
RAGE_API void FreeRGBA(rage::rgba_t *color);
RAGE_API void FreeRGB(rage::rgb_t *color);
RAGE_API void FreeVector3(rage::vector3 *vector3);
RAGE_API void FreeQuat(rage::quat_t *quat);
RAGE_API void FreeVector2(rage::vector2 *vector2);
RAGE_API void FreeClothData(rage::clothData_t *cloth);
RAGE_API void FreeHeadBlend(rage::headBlend_t *headBlend);
RAGE_API void FreePropData(rage::propData_t *prop);
RAGE_API void FreeArg(rage::arg_t *argument);
RAGE_API void FreeArgs(rage::args_t *arguments);
RAGE_API void FreePaintInfo(rage::paintInfo_t *paintInfo);
RAGE_API void FreeHeadOverlay(rage::headOverlay_t *headOverlay);

RAGE_API void FreeString(char *string);

#ifdef __cplusplus
}
#endif

/*
 * File: blip.h
 * Author: MarkAtk
 * Date: 10.10.2018
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#include <ragemp-cppsdk/rage.hpp>
#pragma clang diagnostic pop

#ifdef __cplusplus
extern "C" {
#endif

RAGE_API float Blip_GetDrawDistance(rage::IBlip *blip);
RAGE_API void Blip_SetDrawDistance(rage::IBlip *blip, float distance);
RAGE_API int32_t Blip_GetRotation(rage::IBlip *blip);
RAGE_API void Blip_SetRotation(rage::IBlip *blip, int32_t rotation);
RAGE_API bool Blip_IsShortRange(rage::IBlip *blip);
RAGE_API void Blip_SetShortRange(rage::IBlip *blip, bool toggle);
RAGE_API void Blip_RouteFor(rage::IBlip *blip, rage::IPlayer **players, int count, uint32_t color, float scale);
RAGE_API void Blip_UnrouteFor(rage::IBlip *blip, rage::IPlayer **players, int count);
RAGE_API uint32_t Blip_GetColor(rage::IBlip *blip);
RAGE_API void Blip_SetColor(rage::IBlip *blip, uint32_t color);
//GetAlpha comment out in rage headers
//SetAlpha comment out in rage headers
RAGE_API float Blip_GetScale(rage::IBlip *blip);
RAGE_API void Blip_SetScale(rage::IBlip *blip, float scale);
RAGE_API const char *Blip_GetName(rage::IBlip *blip);
RAGE_API void Blip_SetName(rage::IBlip *blip, const char *name);

#ifdef __cplusplus
}
#endif

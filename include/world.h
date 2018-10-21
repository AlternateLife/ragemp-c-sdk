/*
 * File: world.h
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

RAGE_API const rage::time_t *World_GetTime(rage::IWorld *world);
RAGE_API void World_SetTime(rage::IWorld *world, const rage::time_t time);
RAGE_API const char *World_GetWeather(rage::IWorld *world);
RAGE_API void World_SetWeather(rage::IWorld *world, const char *weather);
RAGE_API void World_SetWeatherTransition(rage::IWorld *world, const char *weather, float time);
RAGE_API void World_RequestIpl(rage::IWorld *world, const char *ipl);
RAGE_API void World_RemoveIpl(rage::IWorld *world, const char *ipl);
RAGE_API bool World_AreTrafficLightsLocked(rage::IWorld *world);
RAGE_API void World_LockTrafficLights(rage::IWorld *world, bool toggle);
RAGE_API int World_GetTrafficLightsState(rage::IWorld *world);
RAGE_API void World_SetTrafficLightsState(rage::IWorld *world, int state);

#ifdef __cplusplus
}
#endif

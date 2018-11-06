/*
 * File: world.cpp
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

#include "world.h"

#include "utils.h"

const rage::time_t *World_GetTime(rage::IWorld *world) {
    return &world->GetTime();
}

void World_SetTime(rage::IWorld *world, const rage::time_t time) {
    world->SetTime(time);
}

const char *World_GetWeather(rage::IWorld *world) {
    return createCopyFromString(world->GetWeather());
}

void World_SetWeather(rage::IWorld *world, const char *weather) {
    world->SetWeather(weather);
}

void World_SetWeatherTransition(rage::IWorld *world, const char *weather, float time) {
    world->SetWeatherTransition(weather, time);
}

void World_RequestIpl(rage::IWorld *world, const char *ipl) {
    world->RequestIpl(ipl);
}

void World_RemoveIpl(rage::IWorld *world, const char *ipl) {
    world->RemoveIpl(ipl);
}

bool World_AreTrafficLightsLocked(rage::IWorld *world) {
    return world->AreTrafficLightsLocked();
}

void World_LockTrafficLights(rage::IWorld *world, bool toggle) {
    world->LockTrafficLights(toggle);
}

int World_GetTrafficLightsState(rage::IWorld *world) {
    return world->GetTrafficLightsState();
}

void World_SetTrafficLightsState(rage::IWorld *world, int state) {
    world->SetTrafficLightsState(state);
}



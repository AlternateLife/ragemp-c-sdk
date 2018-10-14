/*
 * File: blip.cpp
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

#include "blip.h"

#include "utils.h"

float Blip_GetDrawDistance(rage::IBlip *blip) {
    return blip->GetDrawDistance();
}

void Blip_SetDrawDistance(rage::IBlip *blip, float distance) {
    blip->SetDrawDistance(distance);
}

int32_t Blip_GetRotation(rage::IBlip *blip) {
    return blip->GetBlipRotation();
}

void Blip_SetRotation(rage::IBlip *blip, int32_t rotation) {
    blip->SetRotation(rotation);
}

bool Blip_IsShortRange(rage::IBlip *blip) {
    return blip->IsShortRange();
}

void Blip_SetShortRange(rage::IBlip *blip, bool toggle) {
    blip->SetShortRange(toggle);
}

void Blip_RouteFor(rage::IBlip *blip, rage::IPlayer **players, int count, uint32_t color, float scale) {
    blip->RouteFor(getVectorFromArray(players, count), color, scale);
}

void Blip_UnrouteFor(rage::IBlip *blip, rage::IPlayer **players, int count) {
    blip->UnrouteFor(getVectorFromArray(players, count));
}

uint32_t Blip_GetColor(rage::IBlip *blip) {
    return blip->GetColour();
}

void Blip_SetColor(rage::IBlip *blip, uint32_t color) {
    blip->SetColour(color);
}

//GetAlpha
//SetAlpha

float Blip_GetScale(rage::IBlip *blip) {
    return blip->GetScale();
}

void Blip_SetScale(rage::IBlip *blip, float scale) {
    blip->SetScale(scale);
}

const char *Blip_GetName(rage::IBlip *blip) {
    return blip->GetName().c_str();
}

void Blip_SetName(rage::IBlip *blip, const char *name) {
    blip->SetName(name);
}

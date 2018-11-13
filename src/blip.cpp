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
    CATCH_UNHANDLED_EXCEPTION(float, ([blip] () {
        return blip->GetDrawDistance();
    }));
}

void Blip_SetDrawDistance(rage::IBlip *blip, float distance) {
    CATCH_UNHANDLED_EXCEPTION(void, ([blip, distance] () {
        blip->SetDrawDistance(distance);
    }));
}

int32_t Blip_GetRotation(rage::IBlip *blip) {
    CATCH_UNHANDLED_EXCEPTION(int32_t, ([blip] () {
        return blip->GetBlipRotation();
    }));
}

void Blip_SetRotation(rage::IBlip *blip, int32_t rotation) {
    CATCH_UNHANDLED_EXCEPTION(void, ([blip, rotation] () {
        blip->SetRotation(rotation);
    }));
}

bool Blip_IsShortRange(rage::IBlip *blip) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([blip] () {
        return blip->IsShortRange();
    }));
}

void Blip_SetShortRange(rage::IBlip *blip, bool toggle) {
    CATCH_UNHANDLED_EXCEPTION(void, ([blip, toggle] () {
        blip->SetShortRange(toggle);
    }));
}

void Blip_RouteFor(rage::IBlip *blip, rage::IPlayer **players, size_t count, uint32_t color, float scale) {
    CATCH_UNHANDLED_EXCEPTION(void, ([blip, players, count, color, scale] () {
        blip->RouteFor(getVectorFromArray(players, count), color, scale);
    }));
}

void Blip_UnrouteFor(rage::IBlip *blip, rage::IPlayer **players, size_t count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([blip, players, count] () {
        blip->UnrouteFor(getVectorFromArray(players, count));
    }));
}

uint32_t Blip_GetColor(rage::IBlip *blip) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([blip] () {
        return blip->GetColour();
    }));
}

void Blip_SetColor(rage::IBlip *blip, uint32_t color) {
    CATCH_UNHANDLED_EXCEPTION(void, ([blip, color] () {
        blip->SetColour(color);
    }));
}

//GetAlpha
//SetAlpha

float Blip_GetScale(rage::IBlip *blip) {
    CATCH_UNHANDLED_EXCEPTION(float, ([blip] () {
        return blip->GetScale();
    }));
}

void Blip_SetScale(rage::IBlip *blip, float scale) {
    CATCH_UNHANDLED_EXCEPTION(void, ([blip, scale] () {
        blip->SetScale(scale);
    }));
}

const char *Blip_GetName(rage::IBlip *blip) {
    CATCH_UNHANDLED_EXCEPTION(const char *, ([blip] () {
        return createCopyFromString(blip->GetName());
    }));
}

void Blip_SetName(rage::IBlip *blip, const char *name) {
    CATCH_UNHANDLED_EXCEPTION(void, ([blip, name] () {
        blip->SetName(name);
    }));
}

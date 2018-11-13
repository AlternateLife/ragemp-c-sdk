/*
 * File: marker.cpp
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

#include "marker.h"

#include "utils.h"
 
const rage::rgba_t *Marker_GetColor(rage::IMarker *marker) {
    CATCH_UNHANDLED_EXCEPTION(const rage::rgba_t *, ([marker] () {
        return copyStruct(marker->GetColour());
    }));
}

void Marker_SetColor(rage::IMarker *marker, uint32_t red, uint32_t green, uint32_t blue, uint32_t alpha) {
    CATCH_UNHANDLED_EXCEPTION(void, ([marker, red, green, blue, alpha] () {
        marker->SetColour(red, green, blue, alpha);
    }));
}

const rage::vector3 *Marker_GetDirection(rage::IMarker *marker) {
    CATCH_UNHANDLED_EXCEPTION(const rage::vector3 *, ([marker] () {
        return copyStruct(marker->GetDirection());
    }));
}

void Marker_SetDirection(rage::IMarker *marker, const rage::vector3 &direction) {
    CATCH_UNHANDLED_EXCEPTION(void, ([marker, direction] () {
        marker->SetDirection(direction);
    }));
}

float Marker_GetScale(rage::IMarker *marker) {
    CATCH_UNHANDLED_EXCEPTION(float, ([marker] () {
        return marker->GetScale();
    }));
}

void Marker_SetScale(rage::IMarker *marker, float radius) {
    CATCH_UNHANDLED_EXCEPTION(void, ([marker, radius] () {
        marker->SetScale(radius);
    }));
}

bool Marker_IsVisible(rage::IMarker *marker) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([marker] () {
        return marker->IsVisible();
    }));
}

void Marker_SetVisible(rage::IMarker *marker, bool toggle) {
    CATCH_UNHANDLED_EXCEPTION(void, ([marker, toggle] () {
        marker->SetVisible(toggle);
    }));
}

void Marker_ShowFor(rage::IMarker *marker, rage::IPlayer **players, size_t count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([marker, players, count] () {
        marker->ShowFor(getVectorFromArray(players, count));
    }));
}

void Marker_HideFor(rage::IMarker *marker, rage::IPlayer **players, size_t count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([marker, players, count] () {
        marker->HideFor(getVectorFromArray(players, count));
    }));
}
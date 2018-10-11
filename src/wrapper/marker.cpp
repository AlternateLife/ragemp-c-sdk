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

#include "wrapper/marker.h"

#include "utils.h"
 
const rage::rgba_t *Marker_GetColor(rage::IMarker *marker) {
    return &marker->GetColour();
}

void Marker_SetColor(rage::IMarker *marker, uint32_t red, uint32_t green, uint32_t blue, uint32_t alpha) {
    marker->SetColour(red, green, blue, alpha);
}

const rage::vector3 *Marker_GetDirection(rage::IMarker *marker) {
    return &marker->GetDirection();
}

void Marker_SetDirection(rage::IMarker *marker, const rage::vector3 &direction) {
    marker->SetDirection(direction);
}

float Marker_GetScale(rage::IMarker *marker) {
    return marker->GetScale();
}

void Marker_SetScale(rage::IMarker *marker, float radius) {
    marker->SetScale(radius);
}

bool Marker_IsVisible(rage::IMarker *marker) {
    return marker->IsVisible();
}

void Marker_SetVisible(rage::IMarker *marker, bool toggle) {
    marker->SetVisible(toggle);
}

void Marker_ShowFor(rage::IMarker *marker, rage::IPlayer **players, size_t count) {
    marker->ShowFor(getPlayerVector(players, count));
}

void Marker_HideFor(rage::IMarker *marker, rage::IPlayer **players, size_t count) {
    marker->HideFor(getPlayerVector(players, count));
}
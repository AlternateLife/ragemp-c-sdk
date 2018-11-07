/*
 * File: checkpoint.cpp
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

#include "checkpoint.h"

#include "utils.h"

const rage::rgba_t *Checkpoint_GetColor(rage::ICheckpoint *checkpoint) {
    return copyStruct(checkpoint->GetColour());
}

void Checkpoint_SetColor(rage::ICheckpoint *checkpoint, uint32_t red, uint32_t green, uint32_t blue, uint32_t alpha) {
    checkpoint->SetColour(red, green, blue, alpha);
}

const rage::vector3 *Checkpoint_GetDirection(rage::ICheckpoint *checkpoint) {
    return copyStruct(checkpoint->GetDirection());
}

void Checkpoint_SetDirection(rage::ICheckpoint *checkpoint, const rage::vector3 &direction) {
    checkpoint->SetDirection(direction);
}

float Checkpoint_GetRadius(rage::ICheckpoint *checkpoint) {
    return checkpoint->GetRadius();
}

void Checkpoint_SetRadius(rage::ICheckpoint *checkpoint, float radius) {
    checkpoint->SetRadius(radius);
}

bool Checkpoint_IsVisible(rage::ICheckpoint *checkpoint) {
    return checkpoint->IsVisible();
}

void Checkpoint_SetVisible(rage::ICheckpoint *checkpoint, bool toggle) {
    checkpoint->SetVisible(toggle);
}

void Checkpoint_ShowFor(rage::ICheckpoint *checkpoint, rage::IPlayer **players, size_t count) {
    checkpoint->ShowFor(getVectorFromArray(players, count));
}

void Checkpoint_HideFor(rage::ICheckpoint *checkpoint, rage::IPlayer **players, size_t count) {
    checkpoint->HideFor(getVectorFromArray(players, count));
}

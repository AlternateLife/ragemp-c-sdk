/*
 * File: checkpoint.h
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

RAGE_API const rage::rgba_t *Checkpoint_GetColor(rage::ICheckpoint *checkpoint);
RAGE_API void Checkpoint_SetColor(rage::ICheckpoint *checkpoint, uint32_t red, uint32_t green, uint32_t blue, uint32_t alpha);
RAGE_API const rage::vector3 *Checkpoint_GetDirection(rage::ICheckpoint *checkpoint);
RAGE_API void Checkpoint_SetDirection(rage::ICheckpoint *checkpoint, const rage::vector3 direction);
RAGE_API float Checkpoint_GetRadius(rage::ICheckpoint *checkpoint);
RAGE_API void Checkpoint_SetRadius(rage::ICheckpoint *checkpoint, float radius);
RAGE_API bool Checkpoint_IsVisible(rage::ICheckpoint *checkpoint);
RAGE_API void Checkpoint_SetVisible(rage::ICheckpoint *checkpoint, bool toggle);
RAGE_API void Checkpoint_ShowFor(rage::ICheckpoint *checkpoint, rage::IPlayer **players, size_t count);
RAGE_API void Checkpoint_HideFor(rage::ICheckpoint *checkpoint, rage::IPlayer **players, size_t count);

#ifdef __cplusplus
}
#endif

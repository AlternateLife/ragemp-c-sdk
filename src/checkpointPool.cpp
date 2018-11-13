/*
 * File: checkpointPool.cpp
 * Author: MarkAtk
 * Date: 11.10.2018
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

#include "checkpointPool.h"

#include "utils.h"

rage::ICheckpoint *CheckpointPool_New(rage::ICheckpointPool *pool, uint32_t type, const rage::vector3 &position, const rage::vector3 &nextPosition,
        float radius, const rage::rgba_t color, bool visible, uint32_t dimension) {
    CATCH_UNHANDLED_EXCEPTION(rage::ICheckpoint *, ([pool, type, position, nextPosition, radius, color, visible, dimension] () {
        return pool->New(type, position, nextPosition, radius, color, visible, dimension);
    }));
}
/*
 * File: colshapePool.cpp
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

#include "wrapper/colshapePool.h"

rage::IColshape *ColshapePool_NewCircle(rage::IColshapePool *pool, const rage::vector2 &position, float radius, uint32_t dimension) {
    return pool->NewCircle(position, radius, dimension);
}

rage::IColshape *ColshapePool_NewSphere(rage::IColshapePool *pool, const rage::vector3 &position, float radius, uint32_t dimension) {
    return pool->NewSphere(position, radius, dimension);
}

rage::IColshape *ColshapePool_NewTube(rage::IColshapePool *pool, const rage::vector3 &position, float radius, float height, uint32_t dimension) {
    return pool->NewTube(position, radius, height, dimension);
}

rage::IColshape *ColshapePool_NewRectangle(rage::IColshapePool *pool, const rage::vector2 &position, const rage::vector2 &size, uint32_t dimension) {
    return pool->NewRectangle(position, size, dimension);
}

rage::IColshape *ColshapePool_NewCube(rage::IColshapePool *pool, const rage::vector3 &position, const rage::vector3 &size, uint32_t dimension) {
    return pool->NewCube(position, size, dimension);
}


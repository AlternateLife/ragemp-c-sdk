/*
 * File: pool.cpp
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

#include "pool.h"

#include "utils.h"

rage::IEntity *Pool_GetAt(rage::IPool<rage::IEntity> *pool, uint32_t id) {
    return pool->GetAt(id);
}

uint32_t Pool_GetLength(rage::IPool<rage::IEntity> *pool) {
    return pool->Length();
}

uint32_t Pool_GetCount(rage::IPool<rage::IEntity> *pool) {
    return pool->Count();
}

void Pool_GetInRange(rage::IPool<rage::IEntity> *pool, const rage::vector3 &position, float range, uint32_t dimension, rage::IEntity ***entities, size_t *count) {
    getArrayFromVector(pool->GetInRange(position, range, dimension), entities, count);
}

void Pool_GetInDimension(rage::IPool<rage::IEntity> *pool, uint32_t dimension, rage::IEntity ***entities, size_t *count) {
    getArrayFromVector(pool->GetInDimension(dimension), entities, count);
}

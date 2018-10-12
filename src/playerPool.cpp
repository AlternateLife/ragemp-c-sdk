/*
 * File: playerPool.cpp
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

#include "playerPool.h"

#include "utils.h"

void PlayerPool_Broadcast(rage::IPlayerPool *pool, const char *message) {
    pool->Broadcast(message);
}

void PlayerPool_BroadcastInRange(rage::IPlayerPool *pool, const char *message, const rage::vector3 &position, float range, uint32_t dimension) {
    pool->BroadcastInRange(message, position, range, dimension);
}

void PlayerPool_BroadcastInDimension(rage::IPlayerPool *pool, const char *message, uint32_t dimension) {
    pool->BroadcastInDimension(message, dimension);
}

void PlayerPool__Call(rage::IPlayerPool *pool, const char *eventName, const rage::arg_t *arguments, size_t count) {
    pool->_Call(eventName, arguments, count);
}

void PlayerPool__CallInRange(rage::IPlayerPool *pool, const rage::vector3 &position, float range, uint32_t dimension, const char *eventName,
                                      const rage::arg_t *arguments, size_t count) {
    pool->_CallInRange(position, range, dimension, eventName, arguments, count);
}

void PlayerPool__CallInDimension(rage::IPlayerPool *pool, uint32_t dimension, const char *eventName, const rage::arg_t *arguments, size_t count) {
    pool->_CallInDimension(dimension, eventName, arguments, count);
}

void PlayerPool__CallFor(rage::IPlayerPool *pool, rage::IPlayer **players, size_t playerCount, const char *eventName, const rage::arg_t *arguments,
        size_t count) {
    pool->_CallFor(getPlayerVector(players, playerCount), eventName, arguments, count);
}

void PlayerPool__Invoke(rage::IPlayerPool *pool, uint64_t hash, const rage::arg_t *arguments, size_t count) {
    pool->_Invoke(hash, arguments, count);
}

void PlayerPool__InvokeInRange(rage::IPlayerPool *pool, const rage::vector3 &position, float range, uint32_t dimension, uint64_t hash, const
rage::arg_t *arguments, size_t count) {
    pool->_InvokeInRange(position, range, dimension, hash, arguments, count);
}

void PlayerPool__InvokeInDimension(rage::IPlayerPool *pool, uint32_t dimension, uint64_t hash, const rage::arg_t *arguments, size_t count) {
    pool->_InvokeInDimension(dimension, hash, arguments, count);
}

void PlayerPool__InvokeFor(rage::IPlayerPool *pool, rage::IPlayer **players, size_t playerCount, uint64_t hash, const rage::arg_t *arguments,
                                    size_t count) {
    pool->_InvokeFor(getPlayerVector(players, playerCount), hash, arguments, count);
}

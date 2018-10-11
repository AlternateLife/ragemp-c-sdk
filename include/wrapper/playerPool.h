/*
 * File: playerPool.h
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#include <ragemp-cppsdk/rage.hpp>
#pragma clang diagnostic pop

#ifdef __cplusplus
extern "C" {
#endif

RAGE_API void PlayerPool_Broadcast(rage::IPlayerPool *pool, const char *message);
RAGE_API void PlayerPool_BroadcastInRange(rage::IPlayerPool *pool, const char *message, const rage::vector3 &position, float range, uint32_t dimension);
RAGE_API void PlayerPool_BroadcastInDimension(rage::IPlayerPool *pool, const char *message, uint32_t dimension);
RAGE_API void PlayerPool__Call(rage::IPlayerPool *pool, const char *eventName, const rage::arg_t *arguments, size_t count);
RAGE_API void PlayerPool__CallInRange(rage::IPlayerPool *pool, const rage::vector3 &position, float range, uint32_t dimension, const char *eventName,
        const rage::arg_t *arguments, size_t count);
RAGE_API void PlayerPool__CallInDimension(rage::IPlayerPool *pool, uint32_t dimension, const char *eventName, const rage::arg_t *arguments, size_t count);
RAGE_API void PlayerPool__CallFor(rage::IPlayerPool *pool, rage::IPlayer **players, size_t playerCount, const char *eventName, const rage::arg_t *arguments,
        size_t count);
RAGE_API void PlayerPool__Invoke(rage::IPlayerPool *pool, uint64_t hash, const rage::arg_t *arguments, size_t count);
RAGE_API void PlayerPool__InvokeInRange(rage::IPlayerPool *pool, const rage::vector3 &position, float range, uint32_t dimension, uint64_t hash, const
        rage::arg_t *arguments, size_t count);
RAGE_API void PlayerPool__InvokeInDimension(rage::IPlayerPool *pool, uint32_t dimension, uint64_t hash, const rage::arg_t *arguments, size_t count);
RAGE_API void PlayerPool__InvokeFor(rage::IPlayerPool *pool, rage::IPlayer **players, size_t playerCount, uint64_t hash, const rage::arg_t *arguments,
        size_t count);

#ifdef __cplusplus
}
#endif

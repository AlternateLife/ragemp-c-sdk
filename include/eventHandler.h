/*
 * File: eventHandler.h
 * Author: MarkAtk
 * Date: 09.10.2018
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

#include <map>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    EVENT_TYPE_ENTITY_CREATED,
    EVENT_TYPE_ENTITY_DESTROYED,
    EVENT_TYPE_ENTITY_MODEL_CHANGED,

    EVENT_TYPE_PLAYER_JOIN,
    EVENT_TYPE_PLAYER_READY,
    EVENT_TYPE_PLAYER_QUIT,
    EVENT_TYPE_PLAYER_COMMAND,
    EVENT_TYPE_PLAYER_CHAT,
    EVENT_TYPE_PLAYER_DEATH,
    EVENT_TYPE_PLAYER_SPAWN,
    EVENT_TYPE_PLAYER_DAMAGE,
    EVENT_TYPE_PLAYER_WEAPON_CHANGED,
    EVENT_TYPE_PLAYER_REMOTE_EVENT,
    EVENT_TYPE_PLAYER_START_ENTER_VEHICLE,
    EVENT_TYPE_PLAYER_ENTER_VEHICLE,
    EVENT_TYPE_PLAYER_START_EXIT_VEHICLE,
    EVENT_TYPE_PLAYER_EXIT_VEHICLE,

    EVENT_TYPE_VEHICLE_DEATH,
    EVENT_TYPE_VEHICLE_SIREN_TOGGLE,
    EVENT_TYPE_VEHICLE_HORN_TOGGLE,
    EVENT_TYPE_VEHCILE_TRAILER_ATTACHED,
    EVENT_TYPE_VEHICLE_DAMAGE,

    EVENT_TYPE_PLAYER_ENTER_COLSHAPE,
    EVENT_TYPE_PLAYER_EXIT_COLSHAPE,

    EVENT_TYPE_PLAYER_ENTER_CHECKPOINT,
    EVENT_TYPE_PLAYER_EXIT_CHECKPOINT,

    EVENT_TYPE_PLAYER_CREATE_WAYPOINT,
    EVENT_TYPE_PLAYER_REACH_WAYPOINT,

    EVENT_TYPE_PLAYER_STREAM_IN,
    EVENT_TYPE_PLAYER_STREAM_OUT,

    EVENT_TYPE_TICK
} eventType_t;

RAGE_API void RegisterEventHandler(eventType_t type, void *callback);
RAGE_API void UnregisterEventHandler(eventType_t type);

#ifdef __cplusplus
}
#endif

extern std::map<eventType_t, void *> _callbacks;

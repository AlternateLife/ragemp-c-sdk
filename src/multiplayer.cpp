/*
 * File: multiplayer.cpp
 * Author: MarkAtk
 * Date: 08.10.2018
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

#include "multiplayer.h"

#include "utils.h"

void Multiplayer_AddRemoteEventHandler(rage::IMultiplayer *multiplayer, const char *eventName, RemoteEventCallback callback) {
    CATCH_UNHANDLED_EXCEPTION(void, ([multiplayer, eventName, callback] () {
        multiplayer->AddRemoteEventHandler(eventName, callback);
    }));
}

const rage::IPlayerPool *Multiplayer_GetPlayerPool(rage::IMultiplayer *multiplayer) {
    CATCH_UNHANDLED_EXCEPTION(const rage::IPlayerPool *, ([multiplayer] () {
        return &multiplayer->GetPlayerPool();
    }));
}

const rage::IVehiclePool *Multiplayer_GetVehiclePool(rage::IMultiplayer *multiplayer) {
    CATCH_UNHANDLED_EXCEPTION(const rage::IVehiclePool *, ([multiplayer] () {
        return &multiplayer->GetVehiclePool();
    }));
}

const rage::IColshapePool *Multiplayer_GetColshapePool(rage::IMultiplayer *multiplayer) {
    CATCH_UNHANDLED_EXCEPTION(const rage::IColshapePool *, ([multiplayer] () {
        return &multiplayer->GetColshapePool();
    }));
}

const rage::ICheckpointPool *Multiplayer_GetCheckpointPool(rage::IMultiplayer *multiplayer) {
    CATCH_UNHANDLED_EXCEPTION(const rage::ICheckpointPool *, ([multiplayer] () {
        return &multiplayer->GetCheckpointPool();
    }));
}

const rage::IMarkerPool *Multiplayer_GetMarkerPool(rage::IMultiplayer *multiplayer) {
    CATCH_UNHANDLED_EXCEPTION(const rage::IMarkerPool *, ([multiplayer] () {
        return &multiplayer->GetMarkerPool();
    }));
}

const rage::IBlipPool *Multiplayer_GetBlipPool(rage::IMultiplayer *multiplayer) {
    CATCH_UNHANDLED_EXCEPTION(const rage::IBlipPool *, ([multiplayer] () {
        return &multiplayer->GetBlipPool();
    }));
}

const rage::IPickupPool *Multiplayer_GetPickupPool(rage::IMultiplayer *multiplayer) {
    CATCH_UNHANDLED_EXCEPTION(const rage::IPickupPool *, ([multiplayer] () {
        return &multiplayer->GetPickupPool();
    }));
}

const rage::IObjectPool *Multiplayer_GetObjectPool(rage::IMultiplayer *multiplayer) {
    CATCH_UNHANDLED_EXCEPTION(const rage::IObjectPool *, ([multiplayer] () {
        return &multiplayer->GetObjectPool();
    }));
}

const rage::ITextLabelPool *Multiplayer_GetLabelPool(rage::IMultiplayer *multiplayer) {
    CATCH_UNHANDLED_EXCEPTION(const rage::ITextLabelPool *, ([multiplayer] () {
        return &multiplayer->GetLabelPool();
    }));
}

const rage::IWorld *Multiplayer_GetWorld(rage::IMultiplayer *multiplayer) {
    CATCH_UNHANDLED_EXCEPTION(const rage::IWorld *, ([multiplayer] () {
        return &multiplayer->GetWorld();
    }));
}

const rage::IConfig *Multiplayer_GetConfig(rage::IMultiplayer *multiplayer) {
    CATCH_UNHANDLED_EXCEPTION(const rage::IConfig *, ([multiplayer] () {
        return &multiplayer->GetConfig();
    }));
}


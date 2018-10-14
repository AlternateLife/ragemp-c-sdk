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

void Multiplayer_AddRemoteEventHandler(rage::IMultiplayer *multiplayer, const char *eventName, RemoteEventCallback callback) {
    multiplayer->AddRemoteEventHandler(eventName, callback);
}

const rage::IPlayerPool *Multiplayer_GetPlayerPool(rage::IMultiplayer *multiplayer) {
    return &multiplayer->GetPlayerPool();
}

const rage::IVehiclePool *Multiplayer_GetVehiclePool(rage::IMultiplayer *multiplayer) {
    return &multiplayer->GetVehiclePool();
}

const rage::IColshapePool *Multiplayer_GetColshapePool(rage::IMultiplayer *multiplayer) {
    return &multiplayer->GetColshapePool();
}

const rage::ICheckpointPool *Multiplayer_GetCheckpointPool(rage::IMultiplayer *multiplayer) {
    return &multiplayer->GetCheckpointPool();
}

const rage::IMarkerPool *Multiplayer_GetMarkerPool(rage::IMultiplayer *multiplayer) {
    return &multiplayer->GetMarkerPool();
}

const rage::IBlipPool *Multiplayer_GetBlipPool(rage::IMultiplayer *multiplayer) {
    return &multiplayer->GetBlipPool();
}

const rage::IPickupPool *Multiplayer_GetPickupPool(rage::IMultiplayer *multiplayer) {
    return &multiplayer->GetPickupPool();
}

const rage::IObjectPool *Multiplayer_GetObjectPool(rage::IMultiplayer *multiplayer) {
    return &multiplayer->GetObjectPool();
}

const rage::ITextLabelPool *Multiplayer_GetLabelPPool(rage::IMultiplayer *multiplayer) {
    return &multiplayer->GetLabelPool();
}

const rage::IWorld *Multiplayer_GetWorld(rage::IMultiplayer *multiplayer) {
    return &multiplayer->GetWorld();
}

const rage::IConfig *Multiplayer_GetConfig(rage::IMultiplayer *multiplayer) {
    return &multiplayer->GetConfig();
}


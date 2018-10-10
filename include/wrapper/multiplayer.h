/*
 * File: multiplayer.h
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

#pragma once

#include <ragemp-cppsdk/rage.hpp>

#ifdef __cplusplus
extern "C" {
#endif

const rage::IPlayerPool *Multiplayer_GetPlayerPool(rage::IMultiplayer *multiplayer);
const rage::IVehiclePool *Multiplayer_GetVehiclePool(rage::IMultiplayer *multiplayer);
const rage::IColshapePool *Multiplayer_GetColshapePool(rage::IMultiplayer *multiplayer);
const rage::ICheckpointPool *Multiplayer_GetCheckpointPool(rage::IMultiplayer *multiplayer);
const rage::IMarkerPool *Multiplayer_GetMarkerPool(rage::IMultiplayer *multiplayer);
const rage::IBlipPool *Multiplayer_GetBlipPool(rage::IMultiplayer *multiplayer);
const rage::IPickupPool *Multiplayer_GetPickupPool(rage::IMultiplayer *multiplayer);
const rage::IObjectPool *Multiplayer_GetObjectPool(rage::IMultiplayer *multiplayer);
const rage::ITextLabelPool *Multiplayer_GetLabelPPool(rage::IMultiplayer *multiplayer);
const rage::IWorld *Multiplayer_GetWorld(rage::IMultiplayer *multiplayer);
const rage::IConfig *Multiplayer_GetConfig(rage::IMultiplayer *multiplayer);


#ifdef __cplusplus
}
#endif

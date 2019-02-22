/*
 * File: rage.h
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

#include "multiplayer.h"
#include "config.h"
#include "world.h"

#include "entity.h"
#include "blip.h"
#include "colshape.h"
#include "checkpoint.h"
#include "marker.h"
#include "player.h"
#include "textLabel.h"
#include "vehicle.h"

#include "pool.h"
#include "blipPool.h"
#include "checkpointPool.h"
#include "colshapePool.h"
#include "markerPool.h"
#include "objectPool.h"
#include "playerPool.h"
#include "textLabelPool.h"
#include "vehiclePool.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RAGEMP_CUSTOM_INITIALIZE
RAGE_API rage::IPlugin *RageMP_Initialize(rage::IMultiplayer *multiplayer);
#endif

void SetupPlugin(rage::IMultiplayer *multiplayer);
void CleanupPlugin();

RAGE_API void FreeObject(void *pointer);
RAGE_API void FreeArray(void *array);

#ifdef __cplusplus
}
#endif

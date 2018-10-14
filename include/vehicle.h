/*
 * File: vehicle.h
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

#ifdef __cplusplus
extern "C" {
#endif

RAGE_API bool Vehicle_IsSirenActive(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetSirenActive(rage::IVehicle *vehicle, bool toggle);
RAGE_API bool Vehicle_IsHornActive(rage::IVehicle *vehicle);
RAGE_API bool Vehicle_AreHighbeamsActive(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetHighbeamsActive(rage::IVehicle *vehicle, bool toggle);
RAGE_API bool Vehicle_AreLightsActive(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetLightsActive(rage::IVehicle *vehicle, bool toggle);
RAGE_API bool Vehicle_IsEngineActive(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetEngineActive(rage::IVehicle *vehicle, bool toggle);
RAGE_API bool Vehicle_AreTaxiLightsActive(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetTaxiLightsActive(rage::IVehicle *vehicle, bool toggle);
RAGE_API bool Vehicle_IsRocketBoostActive(rage::IVehicle *vehicle);
RAGE_API bool Vehicle_IsBrakeActive(rage::IVehicle *vehicle);
RAGE_API float Vehicle_GetSteerAngle(rage::IVehicle *vehicle);
RAGE_API float Vehicle_GetGasPedalState(rage::IVehicle *vehicle);
RAGE_API float Vehicle_GetEngineHealth(rage::IVehicle *vehicle);
RAGE_API float Vehicle_GetBodyHealth(rage::IVehicle *vehicle);
RAGE_API rage::IPlayer *Vehicle_GetOccupant(rage::IVehicle *vehicle, int32_t seat);
RAGE_API void Vehicle_GetOccupants(rage::IVehicle *vehicle, rage::IPlayer ***players, size_t *count);
RAGE_API void Vehicle_SetOccupant(rage::IVehicle *vehicle, int32_t seat, rage::IPlayer *player);
RAGE_API bool Vehicle_IsLocked(rage::IVehicle *vehicle);
RAGE_API void Vehicle_Lock(rage::IVehicle *vehicle, bool toggle);
RAGE_API bool Vehicle_IsDead(rage::IVehicle *vehicle);
RAGE_API void Vehicle_Explode(rage::IVehicle *vehicle);
RAGE_API void Vehicle_Spawn(rage::IVehicle *vehicle, const rage::vector3 &position, float heading);
RAGE_API uint32_t Vehicle_GetMod(rage::IVehicle *vehicle, uint32_t id);
RAGE_API void Vehicle_SetMod(rage::IVehicle *vehicle, uint32_t id, uint32_t mod);
RAGE_API bool Vehicle_AreNeonsEnabled(rage::IVehicle *vehicle);
RAGE_API void Vehicle_EnableNeons(rage::IVehicle *vehicle, bool toggle);
RAGE_API void Vehicle_SetNeonsColor(rage::IVehicle *vehicle, uint32_t red, uint32_t green, uint32_t blue);
RAGE_API const rage::rgb_t *Vehicle_GetNeonsColor(rage::IVehicle *vehicle);
RAGE_API void Vehicle_Repair(rage::IVehicle *vehicle);
RAGE_API const rage::rgb_t *Vehicle_GetColorRGB(rage::IVehicle *vehicle, uint32_t id);
RAGE_API uint32_t Vehicle_GetColor(rage::IVehicle *vehicle, uint32_t id);
RAGE_API uint32_t Vehicle_GetPaint(rage::IVehicle *vehicle, uint32_t id);
RAGE_API void Vehicle_SetColorRGB(rage::IVehicle *vehicle, const rage::rgb_t &primary, const rage::rgb_t &secondary);
RAGE_API void Vehicle_SetColor(rage::IVehicle *vehicle, uint32_t primary, uint32_t secondary);
RAGE_API void Vehicle_SetPaint(rage::IVehicle *vehicle, const rage::paintInfo_t &primary, const rage::paintInfo_t &secondary);
RAGE_API uint32_t Vehicle_GetMaterialType(rage::IVehicle *vehicle);
RAGE_API const char *Vehicle_GetNumberPlate(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetNumberPlate(rage::IVehicle *vehicle, const char *numberPlate);
RAGE_API bool Vehicle_IsStreamed(rage::IVehicle *vehicle, rage::IPlayer *player);
RAGE_API void Vehicle_GetStreamed(rage::IVehicle *vehicle, rage::IPlayer ***players, size_t *count);
RAGE_API uint32_t Vehicle_GetLivery(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetLivery(rage::IVehicle *vehicle, uint32_t livery);
RAGE_API uint32_t Vehicle_GetWheelColor(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetWheelColor(rage::IVehicle *vehicle, uint32_t color);
RAGE_API uint32_t Vehicle_GetWheelType(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetWheelType(rage::IVehicle *vehicle, uint32_t type);
RAGE_API uint32_t Vehicle_GetNumberPlateType(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetNumberPlateType(rage::IVehicle *vehicle, uint32_t type);
RAGE_API uint32_t Vehicle_GetPearlescentColor(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetPearlescentColor(rage::IVehicle *vehicle, uint32_t color);
RAGE_API uint32_t Vehicle_GetWindowTint(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetWindowTint(rage::IVehicle *vehicle, uint32_t tint);
RAGE_API uint32_t Vehicle_GetDashboardColor(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetDashboardColor(rage::IVehicle *vehicle, uint32_t color);
RAGE_API uint32_t Vehicle_GetTrimColor(rage::IVehicle *vehicle);
RAGE_API void Vehicle_SetTrimColor(rage::IVehicle *vehicle, uint32_t color);
RAGE_API bool Vehicle_GetExtra(rage::IVehicle *vehicle, uint32_t id);
RAGE_API void Vehicle_SetExtra(rage::IVehicle *vehicle, uint32_t id, bool state);
RAGE_API float Vehicle_GetMovableState(rage::IVehicle *vehicle);
RAGE_API const rage::quat_t *Vehicle_GetQuaternion(rage::IVehicle *vehicle);
RAGE_API float Vehicle_GetHeading(rage::IVehicle *vehicle);
RAGE_API rage::IVehicle *Vehicle_GetTrailer(rage::IVehicle *vehicle);
RAGE_API rage::IVehicle *Vehicle_GetTraileredBy(rage::IVehicle *vehicle);

#ifdef __cplusplus
}
#endif

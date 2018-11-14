/*
 * File: vehicle.cpp
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

#include "vehicle.h"

#include "utils.h"

bool Vehicle_IsSirenActive(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle] {
        return vehicle->IsSirenActive();
    }));
}

void Vehicle_SetSirenActive(rage::IVehicle *vehicle, bool toggle) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, toggle] {
        vehicle->SetSirenActive(toggle);
    }));
}

bool Vehicle_IsHornActive(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle] {
        return vehicle->IsHornActive();
    }));
}

bool Vehicle_AreHighbeamsActive(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle] {
        return vehicle->AreHighbeamsActive();
    }));
}

void Vehicle_SetHighbeamsActive(rage::IVehicle *vehicle, bool toggle) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, toggle] {
        vehicle->SetHighbeamsActive(toggle);
    }));
}

bool Vehicle_AreLightsActive(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle] {
        return vehicle->AreLightsActive();
    }));
}

void Vehicle_SetLightsActive(rage::IVehicle *vehicle, bool toggle) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, toggle] {
        vehicle->SetLightsActive(toggle);
    }));
}

bool Vehicle_IsEngineActive(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle] {
        return vehicle->IsEngineActive();
    }));
}

void Vehicle_SetEngineActive(rage::IVehicle *vehicle, bool toggle) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, toggle] {
        vehicle->SetEngineActive(toggle);
    }));
}

bool Vehicle_AreTaxiLightsActive(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle] {
        return vehicle->AreTaxiLightsActive();
    }));
}

void Vehicle_SetTaxiLightsActive(rage::IVehicle *vehicle, bool toggle) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, toggle] {
        vehicle->SetTaxiLightsActive(toggle);
    }));
}

bool Vehicle_IsRocketBoostActive(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle] {
        return vehicle->IsRocketBoostActive();
    }));
}

bool Vehicle_IsBrakeActive(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle] {
        return vehicle->IsBrakeActive();
    }));
}

float Vehicle_GetSteerAngle(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(float, ([vehicle] {
        return vehicle->GetSteerAngle();
    }));
}

float Vehicle_GetGasPedalState(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(float, ([vehicle] {
        return vehicle->GetGasPedalState();
    }));
}

float Vehicle_GetEngineHealth(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(float, ([vehicle] {
        return vehicle->GetEngineHealth();
    }));
}

float Vehicle_GetBodyHealth(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(float, ([vehicle] {
        return vehicle->GetBodyHealth();
    }));
}

rage::IPlayer *Vehicle_GetOccupant(rage::IVehicle *vehicle, int32_t seat) {
    CATCH_UNHANDLED_EXCEPTION(rage::IPlayer *, ([vehicle, seat] {
        return vehicle->GetOccupant(seat);
    }));
}

void Vehicle_GetOccupants(rage::IVehicle *vehicle, rage::IPlayer ***players, size_t *count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, players, count] {
        getArrayFromVector(vehicle->GetOccupants(), players, count);
    }));
}

void Vehicle_SetOccupant(rage::IVehicle *vehicle, int32_t seat, rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, seat, player] {
        vehicle->SetOccupant(seat, player);
    }));
}

bool Vehicle_IsLocked(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle] {
        return vehicle->IsLocked();
    }));
}

void Vehicle_Lock(rage::IVehicle *vehicle, bool toggle) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, toggle] {
        vehicle->Lock(toggle);
    }));
}

bool Vehicle_IsDead(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle] {
        return vehicle->IsDead();
    }));
}

void Vehicle_Explode(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle] {
        vehicle->Explode();
    }));
}

void Vehicle_Spawn(rage::IVehicle *vehicle, const rage::vector3 &position, float heading) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, position, heading] {
        vehicle->Spawn(position, heading);
    }));
}

uint32_t Vehicle_GetMod(rage::IVehicle *vehicle, uint32_t id) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([vehicle, id] {
        return vehicle->GetMod(id);
    }));
}

void Vehicle_SetMod(rage::IVehicle *vehicle, uint32_t id, uint32_t mod) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, id, mod] {
        vehicle->SetMod(id, mod);
    }));
}

bool Vehicle_AreNeonsEnabled(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle] {
        return vehicle->AreNeonsEnabled();
    }));
}

void Vehicle_EnableNeons(rage::IVehicle *vehicle, bool toggle) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, toggle] {
        vehicle->EnableNeons(toggle);
    }));
}

void Vehicle_SetNeonsColor(rage::IVehicle *vehicle, uint32_t red, uint32_t green, uint32_t blue) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, red, green, blue] {
        vehicle->SetNeonsColour(red, green, blue);
    }));
}

const rage::rgb_t *Vehicle_GetNeonsColor(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(const rage::rgb_t *, ([vehicle] {
        return copyStruct(vehicle->GetNeonsColour());
    }));
}

void Vehicle_Repair(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle] {
        vehicle->Repair();
    }));
}

const rage::rgb_t *Vehicle_GetColorRGB(rage::IVehicle *vehicle, uint32_t id) {
    CATCH_UNHANDLED_EXCEPTION(const rage::rgb_t *, ([vehicle, id] {
        return copyStruct(vehicle->GetColourRGB(id));
    }));
}

uint32_t Vehicle_GetColor(rage::IVehicle *vehicle, uint32_t id) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([vehicle, id] {
        return vehicle->GetColour(id);
    }));
}

uint32_t Vehicle_GetPaint(rage::IVehicle *vehicle, uint32_t id) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([vehicle, id] {
        return vehicle->GetPaint(id);
    }));
}

void Vehicle_SetColorRGB(rage::IVehicle *vehicle, const rage::rgb_t primary, const rage::rgb_t secondary) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, primary, secondary] {
        vehicle->SetColourRGB(primary, secondary);
    }));
}

void Vehicle_SetColor(rage::IVehicle *vehicle, uint32_t primary, uint32_t secondary) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, primary, secondary] {
        vehicle->SetColour(primary, secondary);
    }));
}

void Vehicle_SetPaint(rage::IVehicle *vehicle, const rage::paintInfo_t primary, const rage::paintInfo_t secondary) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, primary, secondary] {
        vehicle->SetPaint(primary, secondary);
    }));
}

uint32_t Vehicle_GetMaterialType(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t , ([vehicle] {
        return (uint32_t) vehicle->GetMaterialType();
    }));
}

const char *Vehicle_GetNumberPlate(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(const char *, ([vehicle] {
        return createCopyFromString(vehicle->GetNumberPlate());
    }));
}

void Vehicle_SetNumberPlate(rage::IVehicle *vehicle, const char *numberPlate) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, numberPlate] {
        vehicle->SetNumberPlate(numberPlate);
    }));
}

bool Vehicle_IsStreamed(rage::IVehicle *vehicle, rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle, player] {
        return vehicle->IsStreamed(player);
    }));
}

void Vehicle_GetStreamed(rage::IVehicle *vehicle, rage::IPlayer ***players, size_t *count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, players, count] {
        auto streamedVector = vehicle->GetStreamed();

        *players = (rage::IPlayer **) malloc(streamedVector.size() * sizeof(rage::IPlayer *));
        *count = streamedVector.size();

        for (int i = 0; i < streamedVector.size(); i++) {
            *players[i] = streamedVector[i];
        }
    }));
}

uint32_t Vehicle_GetLivery(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t , ([vehicle] {
        return vehicle->GetLivery();
    }));
}

void Vehicle_SetLivery(rage::IVehicle *vehicle, uint32_t livery) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, livery] {
        vehicle->SetLivery(livery);
    }));
}

uint32_t Vehicle_GetWheelColor(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([vehicle] {
        return vehicle->GetWheelColor();
    }));
}

void Vehicle_SetWheelColor(rage::IVehicle *vehicle, uint32_t color) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, color] {
        vehicle->SetWheelColor(color);
    }));
}

uint32_t Vehicle_GetWheelType(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([vehicle] {
        return vehicle->GetWheelType();
    }));
}

void Vehicle_SetWheelType(rage::IVehicle *vehicle, uint32_t type) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, type] {
        vehicle->SetWheelType(type);
    }));
}

uint32_t Vehicle_GetNumberPlateType(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([vehicle] {
        return vehicle->GetNumberPlateType();
    }));
}

void Vehicle_SetNumberPlateType(rage::IVehicle *vehicle, uint32_t type) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, type] {
        vehicle->SetNumberPlateType(type);
    }));
}

uint32_t Vehicle_GetPearlescentColor(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([vehicle] {
        return vehicle->GetPearlescentColor();
    }));
}

void Vehicle_SetPearlescentColor(rage::IVehicle *vehicle, uint32_t color) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, color] {
        vehicle->SetPearlescentColor(color);
    }));
}

uint32_t Vehicle_GetWindowTint(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([vehicle] {
        return vehicle->GetWindowTint();
    }));
}

void Vehicle_SetWindowTint(rage::IVehicle *vehicle, uint32_t tint) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, tint] {
        vehicle->SetWindowTint(tint);
    }));
}

uint32_t Vehicle_GetDashboardColor(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([vehicle] {
        return vehicle->GetDashboardColor();
    }));
}

void Vehicle_SetDashboardColor(rage::IVehicle *vehicle, uint32_t color) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, color] {
        vehicle->SetDashboardColor(color);
    }));
}

uint32_t Vehicle_GetTrimColor(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([vehicle] {
        return vehicle->GetTrimColor();
    }));
}

void Vehicle_SetTrimColor(rage::IVehicle *vehicle, uint32_t color) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, color] {
        vehicle->SetTrimColor(color);
    }));
}

bool Vehicle_GetExtra(rage::IVehicle *vehicle, uint32_t id) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([vehicle, id] {
        return vehicle->GetExtra(id);
    }));
}

void Vehicle_SetExtra(rage::IVehicle *vehicle, uint32_t id, bool state) {
    CATCH_UNHANDLED_EXCEPTION(void, ([vehicle, id, state] {
        vehicle->SetExtra(id, state);
    }));
}

float Vehicle_GetMovableState(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(float, ([vehicle] {
        return vehicle->GetMovableState();
    }));
}

const rage::quat_t *Vehicle_GetQuaternion(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(const rage::quat_t *, ([vehicle] {
        return copyStruct(vehicle->GetQuaternion());
    }));
}

float Vehicle_GetHeading(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(float, ([vehicle] {
        return vehicle->GetHeading();
    }));
}

rage::IVehicle *Vehicle_GetTrailer(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(rage::IVehicle *, ([vehicle] {
        return vehicle->GetTrailer();
    }));
}

rage::IVehicle *Vehicle_GetTraileredBy(rage::IVehicle *vehicle) {
    CATCH_UNHANDLED_EXCEPTION(rage::IVehicle *, ([vehicle] {
        return vehicle->GetTraileredBy();
    }));
}

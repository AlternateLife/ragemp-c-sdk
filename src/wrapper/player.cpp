/*
 * File: player.cpp
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

#include "wrapper/player.h"

#include <ragemp-cppsdk/rage.hpp>

void Player_Kick(rage::IPlayer *player, const char *reason) {
    player->Kick(reason);
}

void Player_Ban(rage::IPlayer *player, const char *reason) {
    player->Ban(reason);
}

void Player_OutputChatBox(rage::IPlayer *player, const char *text) {
    player->OutputChatBox(text);
}

void Player_Notify(rage::IPlayer *player, const char *text) {
    player->Notify(text);
}

RAGE_API void Player__Call(rage::IPlayer *player, const char *eventName, const rage::arg_t *arguments, size_t count) {
    player->_Call(eventName, arguments, count);
}

RAGE_API void Player__CallHash(rage::IPlayer *player, uint64_t hash, const rage::arg_t *arguments, size_t count) {
    player->_CallHash(hash, arguments, count);
}

RAGE_API void Player__Invoke(rage::IPlayer *player, uint64_t hash, const rage::arg_t *arguments, size_t count) {
    player->_Invoke(hash, arguments, count);
}

void Player_Spawn(rage::IPlayer *player, const rage::vector3 &position, float heading) {
    player->Spawn(position, heading);
}

void Player_PlayAnimation(rage::IPlayer *player, const char *dictionary, const char *name, float speed, int flags) {
    player->PlayAnimation(dictionary, name, speed, flags);
}

void Player_PlayScenario(rage::IPlayer *player, const char *scenario) {
    player->PlayScenario(scenario);
}

void Player_StopAnimation(rage::IPlayer *player) {
    player->StopAnimation();
}

const rage::clothData_t *Player_GetClothes(rage::IPlayer *player, uint32_t id) {
    return &player->GetClothes(id);
}

void Player_SetClothes(rage::IPlayer *player, uint32_t id, const rage::clothData_t &clothes) {
    player->SetClothes(id, clothes);
}

// SetClothes

const rage::propData_t *Player_GetProp(rage::IPlayer *player, uint32_t id) {
    return &player->GetProp(id);
}

void Player_SetProp(rage::IPlayer *player, uint32_t id, const rage::propData_t &prop) {
    player->SetProp(id, prop);
}

// SetProp
// SetCustomization

uint32_t Player_GetDecoration(rage::IPlayer *player, uint32_t collection) {
    return player->GetDecoration(collection);
}

void Player_RemoveDecoration(rage::IPlayer *player, uint32_t collection, uint32_t overlay) {
    player->RemoveDecoration(collection, overlay);
}

void Player_SetDecoration(rage::IPlayer *player, uint32_t collection, uint32_t overlay) {
    player->SetDecoration(collection, overlay);
}

// SetDecoration

void Player_Eval(rage::IPlayer *player, const char *code) {
    player->Eval(code);
}

const char *Player_GetName(rage::IPlayer *player) {
    return player->GetName().c_str();
}

void Player_SetName(rage::IPlayer *player, const char *name) {
    player->SetName(name);
}

bool Player_IsAiming(rage::IPlayer *player) {
    return player->IsAiming();
}

float Player_GetHeading(rage::IPlayer *player) {
    return player->GetHeading();
}

void Player_SetHeading(rage::IPlayer *player, float heading) {
    player->SetHeading(heading);
}

float Player_GetMoveSpeed(rage::IPlayer *player) {
    return player->GetMoveSpeed();
}

float Player_GetHealth(rage::IPlayer *player) {
    return player->GetHealth();
}

void Player_SetHealth(rage::IPlayer *player, float health) {
    player->SetHealth(health);
}

float Player_GetArmor(rage::IPlayer *player) {
    return player->GetArmour();
}

void Player_SetArmor(rage::IPlayer *player, float armor) {
    player->SetArmour(armor);
}

const rage::vector3 *Player_GetAminingAt(rage::IPlayer *player) {
    return &player->GetAimingAt();
}

int Player_GetPing(rage::IPlayer *player) {
    return player->GetPing();
}

float Player_GetPacketLoss(rage::IPlayer *player) {
    return player->GetPacketLoss();
}

const char *Player_GetKickReason(rage::IPlayer *player) {
    return player->GetKickReason().c_str();
}

const char *Player_GetIp(rage::IPlayer *player) {
    return player->GetIp().c_str();
}

bool Player_IsJumping(rage::IPlayer *player) {
    return player->IsJumping();
}

bool Player_IsInCover(rage::IPlayer *player) {
    return player->IsInCover();
}

bool Player_IsEnteringVehicle(rage::IPlayer *player) {
    return player->IsEnteringVehicle();
}

bool Player_IsLeavingVehicle(rage::IPlayer *player) {
    return player->IsLeavingVehicle();
}

bool Player_IsClimbing(rage::IPlayer *player) {
    return player->IsClimbing();
}

bool Player_IsOnLadder(rage::IPlayer *player) {
    return player->IsOnLadder();
}

bool Player_IsReloading(rage::IPlayer *player) {
    return player->IsReloading();
}

bool Player_IsInMelee(rage::IPlayer *player) {
    return player->IsInMelee();
}

const char *Player_GetActionString(rage::IPlayer *player) {
    return player->GetActionString().c_str();
}

rage::IVehicle *Player_GetVehicle(rage::IPlayer *player) {
    return player->GetVehicle();
}

void Player_PutIntoVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, int32_t seat) {
    player->PutIntoVehicle(vehicle, seat);
}

void Player_RemoveFromVehicle(rage::IPlayer *player) {
    player->RemoveFromVehicle();
}

int32_t Player_GetSeat(rage::IPlayer *player) {
    return player->GetSeat();
}

uint32_t Player_GetEyeColor(rage::IPlayer *player) {
    return player->GetEyeColour();
}

void Player_SetEyeColor(rage::IPlayer *player, uint32_t color) {
    player->SetEyeColour(color);
}

uint32_t Player_GetHairColor(rage::IPlayer *player) {
    return player->GetHairColour();
}

uint32_t Player_GetHairHighlightColor(rage::IPlayer *player) {
    return player->GetHairHighlightColour();
}

void Player_SetHairColor(rage::IPlayer *player, uint32_t color, uint32_t highlightColor) {
    player->SetHairColour(color, highlightColor);
}

float Player_GetFaceFeature(rage::IPlayer *player, uint32_t id) {
    return player->GetFaceFeature(id);
}

void Player_SetFaceFeature(rage::IPlayer *player, uint32_t id, float scale) {
    player->SetFaceFeature(id, scale);
}

const rage::headBlend_t *Player_GetHeadBlend(rage::IPlayer *player) {
    return &player->GetHeadBlend();
}

void Player_SetHeadBlend(rage::IPlayer *player, int shapeFirstId, int shapeSecondId, int shapeThirdId, int skinFirstId, int skinSecondId, int
skinThirdId, float shapeMix, float skinMix, float thirdMix) {
    player->SetHeadBlend(shapeFirstId, shapeSecondId, shapeThirdId, skinFirstId, skinSecondId, skinThirdId, shapeMix, skinMix, thirdMix);
}

void Player_UpdateHeadBlend(rage::IPlayer *player, float shapeMix, float skinMix, float thirdMix) {
    player->UpdateHeadBlend(shapeMix, skinMix, thirdMix);
}

const rage::headOverlay_t *Player_GetHeadOverlay(rage::IPlayer *player, uint32_t overlayId) {
    return &player->GetHeadOverlay(overlayId);
}

void Player_SetHeadOverlay(rage::IPlayer *player, uint32_t overlayId, const rage::headOverlay_t &overlay) {
    player->SetHeadOverlay(overlayId, overlay);
}

uint32_t Player_GetCurrentWeapon(rage::IPlayer *player) {
    return player->GetCurrentWeapon();
}

void Player_SetCurrentWeapon(rage::IPlayer *player, uint32_t weapon) {
    player->SetCurrentWeapon(weapon);
}

uint32_t Player_GetCurrentWeaponAmmo(rage::IPlayer *player) {
    return player->GetCurrentWeapon();
}

void Player_SetCurrentWeaponAmmo(rage::IPlayer *player, uint32_t ammo) {
    player->SetCurrentWeapon(ammo);
}

uint32_t Player_GetWeaponAmmo(rage::IPlayer *player, uint32_t weapon) {
    return player->GetWeaponAmmo(weapon);
}

void Player_SetWeaponAmmo(rage::IPlayer *player, uint32_t weapon, uint32_t ammo) {
    player->SetWeaponAmmo(weapon, ammo);
}

// GetWeapons

void Player_GiveWeapon(rage::IPlayer *player, uint32_t weapon, uint32_t ammo) {
    player->GiveWeapon(weapon, ammo);
}

// GiveWeapons

void Player_RemoveWeapon(rage::IPlayer *player, uint32_t weapon) {
    player->RemoveWeapon(weapon);
}

// RemoveWeapons

void Player_RemoveAllWeapons(rage::IPlayer *player) {
    player->RemoveAllWeapons();
}

bool Player_IsStreamed(rage::IPlayer *player, rage::IPlayer *other) {
    return player->IsStreamed(other);
}

// GetStreamed

const char *Player_GetSerial(rage::IPlayer *player) {
    return player->GetSerial().c_str();
}

const char *Player_GetSocialClubName(rage::IPlayer *player) {
    return player->GetSocialClubName().c_str();
}

void Player_RemoveObject(rage::IPlayer *player, uint32_t model, const rage::vector3 &position, float radius) {
    player->RemoveObject(model, position, radius);
}

// Call
// Invoke

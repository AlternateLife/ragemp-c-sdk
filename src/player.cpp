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

#include "player.h"

#include "utils.h"

#include <iostream>
#include <fstream>

void Player_Kick(rage::IPlayer *player, const char *reason) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, reason] () {
        player->Kick(reason);
    }));
}

void Player_Ban(rage::IPlayer *player, const char *reason) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, reason] () {
        player->Ban(reason);
    }));
}

void Player_OutputChatBox(rage::IPlayer *player, const char *text) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, text] () {
        player->OutputChatBox(text);
    }));
}

void Player_Notify(rage::IPlayer *player, const char *text) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, text] () {
        player->Notify(text);
    }));
}

void Player__Call(rage::IPlayer *player, const char *eventName, const rage::arg_t *arguments, size_t count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, eventName, arguments, count] () {
        player->_Call(eventName, arguments, count);
    }));
}

void Player__CallHash(rage::IPlayer *player, uint64_t hash, const rage::arg_t *arguments, size_t count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, hash, arguments, count] () {
        player->_CallHash(hash, arguments, count);
    }));
}

void Player__Invoke(rage::IPlayer *player, uint64_t hash, const rage::arg_t *arguments, size_t count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, hash, arguments, count] () {
        player->_Invoke(hash, arguments, count);
    }));
}

void Player_Spawn(rage::IPlayer *player, const rage::vector3 &position, float heading) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, position, heading] () {
        player->Spawn(position, heading);
    }));
}

void Player_PlayAnimation(rage::IPlayer *player, const char *dictionary, const char *name, float speed, int flags) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, dictionary, name, speed, flags] () {
        player->PlayAnimation(dictionary, name, speed, flags);
    }));
}

void Player_PlayScenario(rage::IPlayer *player, const char *scenario) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, scenario] () {
        player->PlayScenario(scenario);
    }));
}

void Player_StopAnimation(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player] () {
        player->StopAnimation();
    }));
}

const rage::clothData_t *Player_GetClothes(rage::IPlayer *player, uint32_t id) {
    CATCH_UNHANDLED_EXCEPTION(const rage::clothData_t *, ([player, id] () {
        return copyStruct(player->GetClothes(id));
    }));
}

void Player_SetCloth(rage::IPlayer *player, uint32_t id, const rage::clothData_t &clothes) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, id, clothes] () {
        player->SetClothes(id, clothes);
    }));
}

void Player_SetClothes(rage::IPlayer *player, uint32_t *keys, const rage::clothData_t *clothes, size_t count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, keys, clothes, count] () {
        std::vector<std::pair<uint8_t, const rage::clothData_t>> list;

        for (int i = 0; i < count; i++) {
            list.emplace_back(keys[i], clothes[i]);
        }

        player->SetClothes(list);
    }));
}

const rage::propData_t *Player_GetProp(rage::IPlayer *player, uint32_t id) {
    CATCH_UNHANDLED_EXCEPTION(const rage::propData_t *, ([player, id] () {
        return copyStruct(player->GetProp(id));
    }));
}

void Player_SetProp(rage::IPlayer *player, uint32_t id, const rage::propData_t prop) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, id, prop] () {
        player->SetProp(id, prop);
    }));
}

void Player_SetProps(rage::IPlayer *player, uint32_t *keys, const rage::propData_t *props, size_t count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, keys, props, count] () {
        std::vector<std::pair<uint8_t, const rage::propData_t>> list;

        for (int i = 0; i < count; i++) {
            list.emplace_back(keys[i], props[i]);
        }

        player->SetProp(list);
    }));
}

void Player_SetCustomization(rage::IPlayer *player, bool gender, const rage::headBlend_t headBlend, uint32_t eyeColor, uint32_t hairColor,
        uint32_t highlightColor, float *faceFeatureValues, size_t faceFeatureCount, int *headOverlayKeys, rage::headOverlay_t *headOverlayValues,
        size_t headOverlayCount, uint32_t *decorationKeys, uint32_t *decorationValues, size_t decorationCount) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, gender, headBlend, eyeColor, hairColor, highlightColor, faceFeatureValues, faceFeatureCount, headOverlayKeys,
                                      headOverlayValues, headOverlayCount, decorationKeys, decorationValues, decorationCount] () {
        auto faceFeatures = getVectorFromArray(faceFeatureValues, faceFeatureCount);
        auto headOverlays = getMapFromArrays(headOverlayKeys, headOverlayValues, headOverlayCount);
        auto decorations = getUintPairFromArrays(decorationKeys, decorationValues, decorationCount);

        player->SetCustomization(gender, headBlend, eyeColor, hairColor, highlightColor, faceFeatures, headOverlays, decorations);
    }));
}

uint32_t Player_GetDecoration(rage::IPlayer *player, uint32_t collection) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([player, collection] () {
        return player->GetDecoration(collection);
    }));
}

void Player_RemoveDecoration(rage::IPlayer *player, uint32_t collection, uint32_t overlay) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, collection, overlay] () {
        player->RemoveDecoration(collection, overlay);
    }));
}

void Player_SetDecoration(rage::IPlayer *player, uint32_t collection, uint32_t overlay) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, collection, overlay] () {
        player->SetDecoration(collection, overlay);
    }));
}

void Player_SetDecorations(rage::IPlayer *player, uint32_t *keys, uint32_t *values, size_t count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, keys, values, count] () {
        player->SetDecorations(getUintPairFromArrays(keys, values, count));
    }));
}

void Player_ClearDecoration(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player] () {
        player->ClearDecorations();
    }));
}

void Player_EnableVoiceTo(rage::IPlayer *player, rage::IPlayer *target) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, target] () {
        player->EnableVoiceTo(target);
    }));
}

void Player_DisableVoiceTo(rage::IPlayer *player, rage::IPlayer *target) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, target] () {
        player->DisableVoiceTo(target);
    }));
}

void Player_GetVoiceListeners(rage::IPlayer *player, rage::IPlayer ***players, size_t *count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, players, count] () {
        getArrayFromVector(player->GetVoiceListeners(), players, count);
    }));
}

void Player_Eval(rage::IPlayer *player, const char *code) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, code] () {
        player->Eval(code);
    }));
}

const char *Player_GetName(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(const char *, ([player] () {
        return createCopyFromString(player->GetName());
    }));
}

void Player_SetName(rage::IPlayer *player, const char *name) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, name] () {
        player->SetName(name);
    }));
}

bool Player_IsAiming(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([player] () {
        return player->IsAiming();
    }));
}

float Player_GetHeading(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(float, ([player] () {
        return player->GetHeading();
    }));
}

void Player_SetHeading(rage::IPlayer *player, float heading) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, heading] () {
        player->SetHeading(heading);
    }));
}

float Player_GetMoveSpeed(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(float, ([player] () {
        return player->GetMoveSpeed();
    }));
}

float Player_GetHealth(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(float, ([player] () {
        return player->GetHealth();
    }));
}

void Player_SetHealth(rage::IPlayer *player, float health) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, health] () {
        player->SetHealth(health);
    }));
}

float Player_GetArmor(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(float, ([player] () {
        return player->GetArmour();
    }));
}

void Player_SetArmor(rage::IPlayer *player, float armor) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, armor] () {
        player->SetArmour(armor);
    }));
}

const rage::vector3 *Player_GetAminingAt(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(const rage::vector3 *, ([player] () {
        return copyStruct(player->GetAimingAt());
    }));
}

int Player_GetPing(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(int, ([player] () {
        return player->GetPing();
    }));
}

float Player_GetPacketLoss(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(float, ([player] () {
        return player->GetPacketLoss();
    }));
}

const char *Player_GetKickReason(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(const char *, ([player] () {
        return createCopyFromString(player->GetKickReason());
    }));
}

const char *Player_GetIp(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(const char *, ([player] () {
        return createCopyFromString(player->GetIp());
    }));
}

bool Player_IsJumping(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([player] () {
        return player->IsJumping();
    }));
}

bool Player_IsInCover(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([player] () {
        return player->IsInCover();
    }));
}

bool Player_IsEnteringVehicle(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([player] () {
        return player->IsEnteringVehicle();
    }));
}

bool Player_IsLeavingVehicle(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([player] () {
        return player->IsLeavingVehicle();
    }));
}

bool Player_IsClimbing(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([player] () {
        return player->IsClimbing();
    }));
}

bool Player_IsOnLadder(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([player] () {
        return player->IsOnLadder();
    }));
}

bool Player_IsReloading(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([player] () {
        return player->IsReloading();
    }));
}

bool Player_IsInMelee(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([player] () {
        return player->IsInMelee();
    }));
}

const char *Player_GetActionString(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(const char *, ([player] () {
        return createCopyFromString(player->GetActionString());
    }));
}

rage::IVehicle *Player_GetVehicle(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(rage::IVehicle *, ([player] () {
        return player->GetVehicle();
    }));
}

void Player_PutIntoVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, int32_t seat) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, vehicle, seat] () {
        player->PutIntoVehicle(vehicle, seat);
    }));
}

void Player_RemoveFromVehicle(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player] () {
        player->RemoveFromVehicle();
    }));
}

int32_t Player_GetSeat(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(int32_t, ([player] () {
        return (int32_t) ((int8_t) player->GetSeat());
    }));
}

uint32_t Player_GetEyeColor(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([player] () {
        return player->GetEyeColour();
    }));
}

void Player_SetEyeColor(rage::IPlayer *player, uint32_t color) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, color] () {
        player->SetEyeColour(color);
    }));
}

uint32_t Player_GetHairColor(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([player] () {
        return player->GetHairColour();
    }));
}

uint32_t Player_GetHairHighlightColor(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([player] () {
        return player->GetHairHighlightColour();
    }));
}

void Player_SetHairColor(rage::IPlayer *player, uint32_t color, uint32_t highlightColor) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, color, highlightColor] () {
        player->SetHairColour(color, highlightColor);
    }));
}

float Player_GetFaceFeature(rage::IPlayer *player, uint32_t id) {
    CATCH_UNHANDLED_EXCEPTION(float, ([player, id] () {
        return player->GetFaceFeature(id);
    }));
}

void Player_SetFaceFeature(rage::IPlayer *player, uint32_t id, float scale) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, id, scale] () {
        player->SetFaceFeature(id, scale);
    }));
}

const rage::headBlend_t *Player_GetHeadBlend(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(const rage::headBlend_t *, ([player] () {
        return copyStruct(player->GetHeadBlend());
    }));
}

void Player_SetHeadBlend(rage::IPlayer *player, int shapeFirstId, int shapeSecondId, int shapeThirdId, int skinFirstId, int skinSecondId, int
skinThirdId, float shapeMix, float skinMix, float thirdMix) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, shapeFirstId, shapeSecondId, shapeThirdId, skinFirstId, skinSecondId, skinThirdId, shapeMix, skinMix, thirdMix]
    () {
        player->SetHeadBlend(shapeFirstId, shapeSecondId, shapeThirdId, skinFirstId, skinSecondId, skinThirdId, shapeMix, skinMix, thirdMix);
    }));
}

void Player_UpdateHeadBlend(rage::IPlayer *player, float shapeMix, float skinMix, float thirdMix) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, shapeMix, skinMix, thirdMix] () {
        player->UpdateHeadBlend(shapeMix, skinMix, thirdMix);
    }));
}

const rage::headOverlay_t *Player_GetHeadOverlay(rage::IPlayer *player, uint32_t overlayId) {
    CATCH_UNHANDLED_EXCEPTION(const rage::headOverlay_t *, ([player, overlayId] () {
        return copyStruct(player->GetHeadOverlay(overlayId));
    }));
}

void Player_SetHeadOverlay(rage::IPlayer *player, uint32_t overlayId, const rage::headOverlay_t &overlay) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, overlayId, overlay] () {
        player->SetHeadOverlay(overlayId, overlay);
    }));
}

uint32_t Player_GetCurrentWeapon(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([player] () {
        return player->GetCurrentWeapon();
    }));
}

void Player_SetCurrentWeapon(rage::IPlayer *player, uint32_t weapon) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, weapon] () {
        player->SetCurrentWeapon(weapon);
    }));
}

uint32_t Player_GetCurrentWeaponAmmo(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([player] () {
        return player->GetCurrentWeaponAmmo();
    }));
}

void Player_SetCurrentWeaponAmmo(rage::IPlayer *player, uint32_t ammo) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, ammo] () {
        player->SetCurrentWeapon(ammo);
    }));
}

uint32_t Player_GetWeaponAmmo(rage::IPlayer *player, uint32_t weapon) {
    CATCH_UNHANDLED_EXCEPTION(uint32_t, ([player, weapon] () {
        return player->GetWeaponAmmo(weapon);
    }));
}

void Player_SetWeaponAmmo(rage::IPlayer *player, uint32_t weapon, uint32_t ammo) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, weapon, ammo] () {
        player->SetWeaponAmmo(weapon, ammo);
    }));
}

void Player_GetWeapons(rage::IPlayer *player, uint32_t **weapons, uint32_t **ammo, size_t *count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, weapons, ammo, count] () {
        auto map = player->GetWeapons();

        *weapons = (uint32_t *) malloc(map.size() * sizeof(uint32_t));
        *ammo = (uint32_t *) malloc(map.size() * sizeof(uint32_t));
        *count = (uint32_t) map.size();

        int i = 0;

        for (auto &keyValue : map) {
            *weapons[i] = keyValue.first;
            *ammo[i] = keyValue.second;

            i++;
        }
    }));
}

void Player_GiveWeapon(rage::IPlayer *player, uint32_t weapon, uint32_t ammo) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, weapon, ammo] () {
        player->GiveWeapon(weapon, ammo);
    }));
}

void Player_GiveWeapons(rage::IPlayer *player, uint32_t *weapons, uint32_t *ammo, size_t count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, weapons, ammo, count] () {
        std::vector<std::pair<uint32_t, uint16_t>> list;

        for (int i = 0; i < count; i++) {
            list.emplace_back(weapons[i], ammo[i]);
        }

        player->GiveWeapons(list);
    }));
}

void Player_RemoveWeapon(rage::IPlayer *player, uint32_t weapon) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, weapon] () {
        player->RemoveWeapon(weapon);
    }));
}

void Player_RemoveWeapons(rage::IPlayer *player, uint32_t *weapons, size_t count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, weapons, count] () {
        player->RemoveWeapons(getVectorFromArray(weapons, count));
    }));
}

void Player_RemoveAllWeapons(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player] () {
        player->RemoveAllWeapons();
    }));
}

bool Player_IsStreamed(rage::IPlayer *player, rage::IPlayer *other) {
    CATCH_UNHANDLED_EXCEPTION(bool, ([player, other] () {
        return player->IsStreamed(other);
    }));
}

void Player_GetStreamed(rage::IPlayer *player, rage::IPlayer ***players, size_t *count) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, players, count] () {
        getArrayFromVector(player->GetStreamed(), players, count);
    }));
}

const char *Player_GetSerial(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(const char *, ([player] () {
        return createCopyFromString(player->GetSerial());
    }));
}

const char *Player_GetSocialClubName(rage::IPlayer *player) {
    CATCH_UNHANDLED_EXCEPTION(const char *, ([player] () {
        return createCopyFromString(player->GetSocialClubName());
    }));
}

void Player_RemoveObject(rage::IPlayer *player, uint32_t model, const rage::vector3 &position, float radius) {
    CATCH_UNHANDLED_EXCEPTION(void, ([player, model, position, radius] () {
        player->RemoveObject(model, position, radius);
    }));
}

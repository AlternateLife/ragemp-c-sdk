/*
 * File: player.h
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

#include <ragemp-cppsdk/rage.hpp>

#ifdef __cplusplus
extern "C" {
#endif

RAGE_API void Player_Kick(rage::IPlayer *player, const char *reason);
RAGE_API void Player_Ban(rage::IPlayer *player, const char *reason);
RAGE_API void Player_OutputChatBox(rage::IPlayer *player, const char *text);
RAGE_API void Player_Notify(rage::IPlayer *player, const char *text);
RAGE_API void Player__Call(rage::IPlayer *player, const char *eventName, const rage::arg_t *arguments, size_t count);
RAGE_API void Player__CallHash(rage::IPlayer *player, uint64_t hash, const rage::arg_t *arguments, size_t count);
RAGE_API void Player__Invoke(rage::IPlayer *player, uint64_t hash, const rage::arg_t *arguments, size_t count);
RAGE_API void Player_Spawn(rage::IPlayer *player, const rage::vector3 &position, float heading);
RAGE_API void Player_PlayAnimation(rage::IPlayer *player, const char *dictionary, const char *name, float speed, int flags);
RAGE_API void Player_PlayScenario(rage::IPlayer *player, const char *scenario);
RAGE_API void Player_StopAnimation(rage::IPlayer *player);
RAGE_API const rage::clothData_t *Player_GetClothes(rage::IPlayer *player, uint32_t id);
RAGE_API void Player_SetClothes(rage::IPlayer *player, uint32_t id, const rage::clothData_t &clothes);
// SetClothes
RAGE_API const rage::propData_t *Player_GetProp(rage::IPlayer *player, uint32_t id);
RAGE_API void Player_SetProp(rage::IPlayer *player, uint32_t id, const rage::propData_t &prop);
// SetProp
// SetCustomization
RAGE_API uint32_t Player_GetDecoration(rage::IPlayer *player, uint32_t collection);
RAGE_API void Player_RemoveDecoration(rage::IPlayer *player, uint32_t collection, uint32_t overlay);
RAGE_API void Player_SetDecoration(rage::IPlayer *player, uint32_t collection, uint32_t overlay);
// SetDecoration
RAGE_API void Player_Eval(rage::IPlayer *player, const char *code);
RAGE_API const char *Player_GetName(rage::IPlayer *player);
RAGE_API void Player_SetName(rage::IPlayer *player, const char *name);
RAGE_API bool Player_IsAiming(rage::IPlayer *player);
RAGE_API float Player_GetHeading(rage::IPlayer *player);
RAGE_API void Player_SetHeading(rage::IPlayer *player, float heading);
RAGE_API float Player_GetMoveSpeed(rage::IPlayer *player);
RAGE_API float Player_GetHealth(rage::IPlayer *player);
RAGE_API void Player_SetHealth(rage::IPlayer *player, float health);
RAGE_API float Player_GetArmor(rage::IPlayer *player);
RAGE_API void Player_SetArmor(rage::IPlayer *player, float armor);
RAGE_API const rage::vector3 *Player_GetAminingAt(rage::IPlayer *player);
RAGE_API int Player_GetPing(rage::IPlayer *player);
RAGE_API float Player_GetPacketLoss(rage::IPlayer *player);
RAGE_API const char *Player_GetKickReason(rage::IPlayer *player);
RAGE_API const char *Player_GetIp(rage::IPlayer *player);
RAGE_API bool Player_IsJumping(rage::IPlayer *player);
RAGE_API bool Player_IsInCover(rage::IPlayer *player);
RAGE_API bool Player_IsEnteringVehicle(rage::IPlayer *player);
RAGE_API bool Player_IsLeavingVehicle(rage::IPlayer *player);
RAGE_API bool Player_IsClimbing(rage::IPlayer *player);
RAGE_API bool Player_IsOnLadder(rage::IPlayer *player);
RAGE_API bool Player_IsReloading(rage::IPlayer *player);
RAGE_API bool Player_IsInMelee(rage::IPlayer *player);
RAGE_API const char *Player_GetActionString(rage::IPlayer *player);
RAGE_API rage::IVehicle *Player_GetVehicle(rage::IPlayer *player);
RAGE_API void Player_PutIntoVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, int32_t seat);
RAGE_API void Player_RemoveFromVehicle(rage::IPlayer *player);
RAGE_API int32_t Player_GetSeat(rage::IPlayer *player);
RAGE_API uint32_t Player_GetEyeColor(rage::IPlayer *player);
RAGE_API void Player_SetEyeColor(rage::IPlayer *player, uint32_t color);
RAGE_API uint32_t Player_GetHairColor(rage::IPlayer *player);
RAGE_API uint32_t Player_GetHairHighlightColor(rage::IPlayer *player);
RAGE_API void Player_SetHairColor(rage::IPlayer *player, uint32_t color, uint32_t highlightColor);
RAGE_API float Player_GetFaceFeature(rage::IPlayer *player, uint32_t id);
RAGE_API void Player_SetFaceFeature(rage::IPlayer *player, uint32_t id, float scale);
RAGE_API const rage::headBlend_t *Player_GetHeadBlend(rage::IPlayer *player);
RAGE_API void Player_SetHeadBlend(rage::IPlayer *player, int shapeFirstId, int shapeSecondId, int shapeThirdId, int skinFirstId, int skinSecondId, int
    skinThirdId, float shapeMix, float skinMix, float thirdMix);
RAGE_API void Player_UpdateHeadBlend(rage::IPlayer *player, float shapeMix, float skinMix, float thirdMix);
RAGE_API const rage::headOverlay_t *Player_GetHeadOverlay(rage::IPlayer *player, uint32_t overlayId);
RAGE_API void Player_SetHeadOverlay(rage::IPlayer *player, uint32_t overlayId, const rage::headOverlay_t &overlay);
RAGE_API uint32_t Player_GetCurrentWeapon(rage::IPlayer *player);
RAGE_API void Player_SetCurrentWeapon(rage::IPlayer *player, uint32_t weapon);
RAGE_API uint32_t Player_GetCurrentWeaponAmmo(rage::IPlayer *player);
RAGE_API void Player_SetCurrentWeaponAmmo(rage::IPlayer *player, uint32_t ammo);
RAGE_API uint32_t Player_GetWeaponAmmo(rage::IPlayer *player, uint32_t weapon);
RAGE_API void Player_SetWeaponAmmo(rage::IPlayer *player, uint32_t weapon, uint32_t ammo);
// GetWeapons
RAGE_API void Player_GiveWeapon(rage::IPlayer *player, uint32_t weapon, uint32_t ammo);
// GiveWeapons
RAGE_API void Player_RemoveWeapon(rage::IPlayer *player, uint32_t weapon);
// RemoveWeapons
RAGE_API void Player_RemoveAllWeapons(rage::IPlayer *player);
RAGE_API bool Player_IsStreamed(rage::IPlayer *player, rage::IPlayer *other);
// GetStreamed
RAGE_API const char *Player_GetSerial(rage::IPlayer *player);
RAGE_API const char *Player_GetSocialClubName(rage::IPlayer *player);
RAGE_API void Player_RemoveObject(rage::IPlayer *player, uint32_t model, const rage::vector3 &position, float radius);
// Call
// Invoke

#ifdef __cplusplus
}
#endif

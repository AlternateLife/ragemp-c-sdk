/*
 * File: plugin.cpp
 * Author: MarkAtk
 * Date: 05.11.2018
 *
 * MIT License
 *
 * Copyright (c) 2018 RageMP-CLR-Host
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

#include "plugin.h"

#include "rage.h"

#include <iostream>

Plugin::Plugin(rage::IMultiplayer *multiplayer) {
    std::cout << "[C] Loading plugin" << std::endl;

    multiplayer->AddEventHandler(this);

    SetupPlugin(multiplayer);

    std::cout << "[C] Loaded plugin" << std::endl;
}

void Plugin::Unload() {
    std::cout << "[C] Unloading plugin" << std::endl;

    CleanupPlugin();

    std::cout << "[C] Unloaded plugin" << std::endl;
}

rage::IEntityHandler *Plugin::GetEntityHandler() {
    return this;
}

rage::IPlayerHandler *Plugin::GetPlayerHandler() {
    return this;
}

rage::IVehicleHandler *Plugin::GetVehicleHandler() {
    return this;
}

rage::IColshapeHandler *Plugin::GetColshapeHandler() {
    return this;
}

rage::ICheckpointHandler *Plugin::GetCheckpointHandler() {
    return this;
}

rage::IBlipHandler *Plugin::GetBlipHandler() {
    return this;
}

rage::IStreamerHandler *Plugin::GetStreamerHandler() {
    return this;
}

rage::ITickHandler* Plugin::GetTickHandler() {
    return this;
}

void Plugin::OnEntityCreated(rage::IEntity *entity) {
    executeCallback(EVENT_TYPE_ENTITY_CREATED, entity);
}

void Plugin::OnEntityDestroyed(rage::IEntity *entity) {
    executeCallback(EVENT_TYPE_ENTITY_DESTROYED, entity);
}

void Plugin::OnEntityModelChange(rage::IEntity *entity, rage::hash_t oldModel) {
    executeCallback(EVENT_TYPE_ENTITY_MODEL_CHANGED, oldModel);
}

void Plugin::OnPlayerJoin(rage::IPlayer *player) {
    executeCallback(EVENT_TYPE_PLAYER_JOIN, player);
}

void Plugin::OnPlayerReady(rage::IPlayer *player) {
    executeCallback(EVENT_TYPE_PLAYER_READY, player);
}

void Plugin::OnPlayerQuit(rage::IPlayer *player, rage::exit_t type, const char *reason) {
    executeCallback(EVENT_TYPE_PLAYER_QUIT, player, type, reason);
}

void Plugin::OnPlayerCommand(rage::IPlayer *player, const std::u16string &command) {
    executeCallback(EVENT_TYPE_PLAYER_COMMAND, player, command.c_str());
}

void Plugin::OnPlayerChat(rage::IPlayer *player, const std::u16string &text) {
    executeCallback(EVENT_TYPE_PLAYER_CHAT, player, text.c_str());
}

void Plugin::OnPlayerDeath(rage::IPlayer *player, rage::hash_t reason, rage::IPlayer *killer) {
    executeCallback(EVENT_TYPE_PLAYER_DEATH, player, reason, killer);
}

void Plugin::OnPlayerSpawn(rage::IPlayer *player) {
    executeCallback(EVENT_TYPE_PLAYER_SPAWN, player);
}

void Plugin::OnPlayerDamage(rage::IPlayer *player, float healthLoss, float armorLoss) {
    executeCallback(EVENT_TYPE_PLAYER_DAMAGE, player, healthLoss, armorLoss);
}

void Plugin::OnPlayerWeaponChange(rage::IPlayer *player, rage::hash_t oldWeapon, rage::hash_t newWeapon) {
    executeCallback(EVENT_TYPE_PLAYER_WEAPON_CHANGED, player, oldWeapon, newWeapon);
}

void Plugin::OnPlayerRemoteEvent(rage::IPlayer *player, uint64_t eventNameHash, const rage::args_t &args) {
    executeCallback(EVENT_TYPE_PLAYER_REMOTE_EVENT, player, eventNameHash, args);
}

void Plugin::OnPlayerStartEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {
    executeCallback(EVENT_TYPE_PLAYER_START_ENTER_VEHICLE, player, vehicle, (int32_t)((int8_t)seatId));
}

void Plugin::OnPlayerEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {
    executeCallback(EVENT_TYPE_PLAYER_ENTER_VEHICLE, player, vehicle, (int32_t)((int8_t)seatId));
}

void Plugin::OnPlayerStartExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {
    executeCallback(EVENT_TYPE_PLAYER_START_EXIT_VEHICLE, player, vehicle);
}

void Plugin::OnPlayerExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {
    executeCallback(EVENT_TYPE_PLAYER_EXIT_VEHICLE, player, vehicle);
}

void Plugin::OnVehicleDeath(rage::IVehicle *vehicle, rage::hash_t hash, rage::IPlayer *killer) {
    executeCallback(EVENT_TYPE_VEHICLE_DEATH, vehicle, hash, killer);
}

void Plugin::OnVehicleSirenToggle(rage::IVehicle *vehicle, bool toggle) {
    executeCallback(EVENT_TYPE_VEHICLE_SIREN_TOGGLE, vehicle, toggle);
}

void Plugin::OnVehicleHornToggle(rage::IVehicle *vehicle, bool toggle) {
    executeCallback(EVENT_TYPE_VEHICLE_HORN_TOGGLE, vehicle, toggle);
}

void Plugin::OnTrailerAttached(rage::IVehicle *vehicle, rage::IVehicle *trailer) {
    executeCallback(EVENT_TYPE_VEHICLE_TRAILER_ATTACHED, vehicle, trailer);
}

void Plugin::OnVehicleDamage(rage::IVehicle *vehicle, float bodyHealthLoss, float engineHealthLoss) {
    executeCallback(EVENT_TYPE_VEHICLE_DAMAGE, vehicle, bodyHealthLoss, engineHealthLoss);
}

void Plugin::OnPlayerEnterColshape(rage::IPlayer *player, rage::IColshape *colshape) {
    executeCallback(EVENT_TYPE_PLAYER_ENTER_COLSHAPE, player, colshape);
}

void Plugin::OnPlayerExitColshape(rage::IPlayer *player, rage::IColshape *colshape) {
    executeCallback(EVENT_TYPE_PLAYER_EXIT_COLSHAPE, player, colshape);
}

void Plugin::OnPlayerEnterCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) {
    executeCallback(EVENT_TYPE_PLAYER_ENTER_CHECKPOINT, player, checkpoint);
}

void Plugin::OnPlayerExitCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) {
    executeCallback(EVENT_TYPE_PLAYER_EXIT_CHECKPOINT, player, checkpoint);
}

void Plugin::OnPlayerCreateWaypoint(rage::IPlayer *player, const rage::vector3 &position) {
    executeCallback(EVENT_TYPE_PLAYER_CREATE_WAYPOINT, player, position);
}

void Plugin::OnPlayerReachWaypoint(rage::IPlayer *player) {
    executeCallback(EVENT_TYPE_PLAYER_REACH_WAYPOINT, player);
}

void Plugin::OnPlayerStreamIn(rage::IPlayer *player, rage::IPlayer *forplayer) {
    executeCallback(EVENT_TYPE_PLAYER_STREAM_IN, player, forplayer);
}

void Plugin::OnPlayerStreamOut(rage::IPlayer *player, rage::IPlayer *forplayer) {
    executeCallback(EVENT_TYPE_PLAYER_STREAM_OUT, player, forplayer);
}

void Plugin::Tick() {
    executeCallback(EVENT_TYPE_TICK);
}

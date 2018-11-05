/*
 * File: plugin.h
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

#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#endif
#include <ragemp-cppsdk/rage.hpp>
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include "events.h"

class Plugin : public rage::IPlugin, public rage::IEventHandler, public rage::IEntityHandler, public rage::IPlayerHandler, public rage::IVehicleHandler,
        public rage::IColshapeHandler, public rage::ICheckpointHandler, public rage::IBlipHandler, public rage::IStreamerHandler, public rage::ITickHandler {
public:
    explicit Plugin(rage::IMultiplayer *multiplayer);
    virtual ~Plugin() = default;

    void Unload() override;

    rage::IEntityHandler *GetEntityHandler() override;
    rage::IPlayerHandler *GetPlayerHandler() override;
    rage::IVehicleHandler *GetVehicleHandler() override;
    rage::IColshapeHandler *GetColshapeHandler() override;
    rage::ICheckpointHandler *GetCheckpointHandler() override;
    rage::IBlipHandler *GetBlipHandler() override;
    rage::IStreamerHandler *GetStreamerHandler() override;
    rage::ITickHandler *GetTickHandler() override;

    void OnEntityCreated(rage::IEntity *entity) override;
    void OnEntityDestroyed(rage::IEntity *entity) override;
    void OnEntityModelChange(rage::IEntity *entity, rage::hash_t oldModel) override;

    void OnPlayerJoin(rage::IPlayer *player) override;
    void OnPlayerReady(rage::IPlayer *player) override;
    void OnPlayerQuit(rage::IPlayer *player, rage::exit_t type, const char *reason) override;
    void OnPlayerCommand(rage::IPlayer *player, const std::u16string& command) override;
    void OnPlayerChat(rage::IPlayer *player, const std::u16string& text) override;
    void OnPlayerDeath(rage::IPlayer *player, rage::hash_t reason, rage::IPlayer *killer) override;
    void OnPlayerSpawn(rage::IPlayer *player) override;
    void OnPlayerDamage(rage::IPlayer *player, float healthLoss, float armorLoss) override;
    void OnPlayerWeaponChange(rage::IPlayer *player, rage::hash_t oldWeapon, rage::hash_t newWeapon) override;
    void OnPlayerRemoteEvent(rage::IPlayer *player, uint64_t eventNameHash, const rage::args_t& args) override;
    void OnPlayerStartEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) override;
    void OnPlayerEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) override;
    void OnPlayerStartExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) override;
    void OnPlayerExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) override;

    void OnVehicleDeath(rage::IVehicle *vehicle, rage::hash_t hash, rage::IPlayer *killer) override;
    void OnVehicleSirenToggle(rage::IVehicle *vehicle, bool toggle) override;
    void OnVehicleHornToggle(rage::IVehicle *vehicle, bool toggle) override;
    void OnTrailerAttached(rage::IVehicle *vehicle, rage::IVehicle *trailer) override;
    void OnVehicleDamage(rage::IVehicle *vehicle, float bodyHealthLoss, float engineHealthLoss) override;

    void OnPlayerEnterColshape(rage::IPlayer *player, rage::IColshape *colshape) override;
    void OnPlayerExitColshape(rage::IPlayer *player, rage::IColshape *colshape) override;

    void OnPlayerEnterCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) override;
    void OnPlayerExitCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) override;

    void OnPlayerCreateWaypoint(rage::IPlayer *player, const rage::vector3& position) override;
    void OnPlayerReachWaypoint(rage::IPlayer *player) override;

    void OnPlayerStreamIn(rage::IPlayer *player, rage::IPlayer *forplayer) override;
    void OnPlayerStreamOut(rage::IPlayer *player, rage::IPlayer *forplayer) override;

    void Tick() override;

private:
    template<class ... Types>
    void executeCallback(eventType_t type, Types ... args) {
        auto callback = _callbacks.find(type);
        if (callback == _callbacks.end() || callback->second == 0) {
            return;
        }

        typedef void (Callback)(Types...);

        ((Callback *)callback->second)(args...);
    }
};

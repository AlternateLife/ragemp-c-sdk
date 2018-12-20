/*
 * File: entity.cpp
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

#include "entity.h"

#include "utils.h"

#define XXH_INLINE_ALL

#include <xxhash/xxhash.h>

uint32_t Entity_GetId(rage::IEntity *entity) {
    return entity->GetId();
}

uint32_t Entity_GetType(rage::IEntity *entity) {
    return (uint32_t)entity->GetType();
}

void Entity_Destroy(rage::IEntity *entity) {
    entity->Destroy();
}

uint32_t Entity_GetDimension(rage::IEntity *entity) {
    return entity->GetDimension();
}

void Entity_SetDimension(rage::IEntity *entity, uint32_t dimension) {
    entity->SetDimension(dimension);
}

const rage::vector3 *Entity_GetPosition(rage::IEntity *entity) {
    return copyStruct(entity->GetPosition());
}

void Entity_SetPosition(rage::IEntity *entity, rage::vector3 position) {
    entity->SetPosition(position);
}

const rage::vector3 *Entity_GetRotation(rage::IEntity *entity) {
    return copyStruct(entity->GetRotation());
}

void Entity_SetRotation(rage::IEntity *entity, rage::vector3 rotation) {
    entity->SetRotation(rotation);
}

uint32_t Entity_GetModel(rage::IEntity *entity) {
    return entity->GetModel();
}

void Entity_SetModel(rage::IEntity *entity, uint32_t model) {
    entity->SetModel(model);
}

const rage::vector3 *Entity_GetVelocity(rage::IEntity *entity) {
    return copyStruct(entity->GetVelocity());
}

uint32_t Entity_GetAlpha(rage::IEntity *entity) {
    return entity->GetAlpha();
}

void Entity_SetAlpha(rage::IEntity *entity, uint32_t alpha) {
    entity->SetAlpha(alpha);
}

const rage::arg_t *Entity_GetVariable(rage::IEntity *entity, const char *key) {
    auto hashedKey = XXH64(key, strlen(key), 0);

    return copyStruct(entity->GetVariable(hashedKey));
}

void Entity_SetVariable(rage::IEntity *entity, const char *key, const rage::arg_t argument) {
    auto hashedKey = XXH64(key, strlen(key), 0);

    entity->SetVariable(hashedKey, argument);
}

void Entity_SetVariables(rage::IEntity *entity, const char **keys, const rage::arg_t *values, size_t count) {
    std::vector<std::pair<uint64_t, const rage::arg_t &>> list;

    for (int i = 0; i < count; i++) {
        auto hashedKey = XXH64(keys[i], strlen(keys[i]), 0);

        list.emplace_back(hashedKey, values[i]);
    }

    entity->SetVariables(list);
}

bool Entity_HasVariable(rage::IEntity *entity, const char *key) {
    auto hashedKey = XXH64(key, strlen(key), 0);

    return entity->HasVariable(hashedKey);
}

const rage::arg_t *Entity_GetVariableHashedKey(rage::IEntity *entity, uint64_t key) {
    return copyStruct(entity->GetVariable(key));
}

void Entity_SetVariableHashedKey(rage::IEntity *entity, uint64_t key, const rage::arg_t argument) {
    entity->SetVariable(key, argument);
}

void Entity_SetVariablesHashedKey(rage::IEntity *entity, uint64_t *keys, const rage::arg_t *values, size_t count) {
    std::vector<std::pair<uint64_t, const rage::arg_t &>> list;

    for (int i = 0; i < count; i++) {
        list.emplace_back(keys[i], values[i]);
    }

    entity->SetVariables(list);
}

bool Entity_HasVariableHashedKey(rage::IEntity *entity, uint64_t key) {
    return entity->HasVariable(key);
}

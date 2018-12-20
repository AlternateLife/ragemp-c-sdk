/*
 * File: entity.h
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

RAGE_API uint32_t Entity_GetId(rage::IEntity *entity);
RAGE_API uint32_t Entity_GetType(rage::IEntity *entity);
RAGE_API void Entity_Destroy(rage::IEntity *entity);
RAGE_API uint32_t Entity_GetDimension(rage::IEntity *entity);
RAGE_API void Entity_SetDimension(rage::IEntity *entity, uint32_t dimension);
RAGE_API const rage::vector3 *Entity_GetPosition(rage::IEntity *entity);
RAGE_API void Entity_SetPosition(rage::IEntity *entity, rage::vector3 position);
RAGE_API const rage::vector3 *Entity_GetRotation(rage::IEntity *entity);
RAGE_API void Entity_SetRotation(rage::IEntity *entity, rage::vector3 rotation);
RAGE_API uint32_t Entity_GetModel(rage::IEntity *entity);
RAGE_API void Entity_SetModel(rage::IEntity *entity, uint32_t model);
RAGE_API const rage::vector3 *Entity_GetVelocity(rage::IEntity *entity);
RAGE_API uint32_t Entity_GetAlpha(rage::IEntity *entity);
RAGE_API void Entity_SetAlpha(rage::IEntity *entity, uint32_t alpha);
RAGE_API const rage::arg_t *Entity_GetVariable(rage::IEntity *entity, const char *key);
RAGE_API void Entity_SetVariable(rage::IEntity *entity, const char *key, const rage::arg_t argument);
RAGE_API void Entity_SetVariables(rage::IEntity *entity, const char **keys, const rage::arg_t *values, size_t count);
RAGE_API bool Entity_HasVariable(rage::IEntity *entity, const char *key);
RAGE_API const rage::arg_t *Entity_GetVariableHashedKey(rage::IEntity *entity, uint64_t key);
RAGE_API void Entity_SetVariableHashedKey(rage::IEntity *entity, uint64_t key, const rage::arg_t argument);
RAGE_API void Entity_SetVariablesHashedKey(rage::IEntity *entity, uint64_t *keys, const rage::arg_t *values, size_t count);
RAGE_API bool Entity_HasVariableHashedKey(rage::IEntity *entity, uint64_t key);

#ifdef __cplusplus
}
#endif

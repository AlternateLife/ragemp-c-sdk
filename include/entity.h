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

#include <ragemp-cppsdk/rage.hpp>

#ifdef __cplusplus
extern "C" {
#endif

RAGE_API uint32_t Entity_GetId(rage::IEntity *entity);
RAGE_API uint32_t Entity_GetType(rage::IEntity *entity);
RAGE_API void Entity_Destroy(rage::IEntity *entity);
RAGE_API uint32_t Entity_GetDimension(rage::IEntity *entity);
RAGE_API void Entity_SetDimension(rage::IEntity *entity, uint32_t dimension);
//RAGE_API const rage::vector3 &Entity_GetPosition(rage::IEntity *entity);
RAGE_API void Entity_SetPosition(rage::IEntity *entity, rage::vector3 &position);
//RAGE_API const rage::vector3 &Entity_GetRotation(rage::IEntity *entity);
RAGE_API void Entity_SetRotation(rage::IEntity *entity, rage::vector3 &rotation);
RAGE_API uint32_t Entity_GetModel(rage::IEntity *entity);
RAGE_API void Entity_SetModel(rage::IEntity *entity, uint32_t model);
//RAGE_API const rage::vector3 &Entity_GetVelocity(rage::IEntity *entity);
RAGE_API uint32_t Entity_GetAlpha(rage::IEntity *entity);
RAGE_API void Entity_SetAlpha(rage::IEntity *entity, uint32_t alpha);
// GetVariable
// SetVariable
// SetVariables
// HasVariable

#ifdef __cplusplus
}
#endif

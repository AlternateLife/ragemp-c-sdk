/*
 * File: textLabel.h
 * Author: MarkAtk
 * Date: 10.10.2018
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

//GetColor
//SetColor
RAGE_API const char *TextLabel_GetText(rage::ITextLabel *textLabel);
RAGE_API void TextLabel_SetText(rage::ITextLabel *textLabel, const char *text);
RAGE_API bool TextLabel_GetLOS(rage::ITextLabel *textLabel);
RAGE_API void TextLabel_SetLos(rage::ITextLabel *textLabel, bool toggle);
RAGE_API float TextLabel_GetDrawDistance(rage::ITextLabel *textLabel);
RAGE_API void TextLabel_SetDrawDistance(rage::ITextLabel *textLabel, float distance);
RAGE_API uint32_t TextLabel_GetFont(rage::ITextLabel *textLabel);
RAGE_API void TextLabel_SetFont(rage::ITextLabel *textLabel, uint32_t font);

#ifdef __cplusplus
}
#endif

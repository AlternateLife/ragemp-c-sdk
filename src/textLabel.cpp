/*
 * File: textLabel.cpp
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

#include "textLabel.h"

const rage::rgba_t *TextLabel_GetColor(rage::ITextLabel *textLabel) {
    return &textLabel->GetColor();
}

void TextLabel_SetColor(rage::ITextLabel *textLabel, const rage::rgba_t color) {
    textLabel->SetColor(color);
}

const char *TextLabel_GetText(rage::ITextLabel *textLabel) {
    return textLabel->GetText().c_str();
}

void TextLabel_SetText(rage::ITextLabel *textLabel, const char *text) {
    textLabel->SetText(text);
}

bool TextLabel_GetLOS(rage::ITextLabel *textLabel) {
    return textLabel->GetLOS();
}

void TextLabel_SetLOS(rage::ITextLabel *textLabel, bool toggle) {
    textLabel->SetLOS(toggle);
}

float TextLabel_GetDrawDistance(rage::ITextLabel *textLabel) {
    return textLabel->GetDrawDistance();
}

void TextLabel_SetDrawDistance(rage::ITextLabel *textLabel, float distance) {
    textLabel->SetDrawDistance(distance);
}

uint32_t TextLabel_GetFont(rage::ITextLabel *textLabel) {
    return textLabel->GetFont();
}

void TextLabel_SetFont(rage::ITextLabel *textLabel, uint32_t font) {
    textLabel->SetFont(font);
}



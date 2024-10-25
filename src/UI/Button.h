#pragma once
#include "raylib.h"

struct Button
{
    Rectangle button;
    Texture off;
    Texture on;
};

bool clickButton(Button button);

bool onButton(Button button);

void drawButton(Button button);


    
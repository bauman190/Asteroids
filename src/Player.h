#pragma once
#include "raylib.h"

struct player
{
	float x;
	float y;
	int lives;
	float maxSpeed;
	Vector2 speed;
	Texture2D texture;
	Rectangle textureProperties;
	Rectangle texturePos;
};

float shipRotation(player player);
void playerMovment(player& player);
void screenLimits(player& player);
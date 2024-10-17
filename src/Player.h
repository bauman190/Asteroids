#pragma once
#include "raylib.h"

struct player
{
	float x;
	float y;
	int lives;
	float speed;
	Texture2D texture;
	Rectangle textureProperties;
	Rectangle texturePos;
};

void moveUp(player& player);
void moveDown(player& player);
void moveLeft(player& player);
void moveRight(player& player);
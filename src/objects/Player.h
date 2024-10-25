#pragma once
#include "raylib.h"

#include "objects/Bullet.h"
#include "tools/Circle.h"
#include "tools/texture_info.h"


struct player
{
	Circle collider;
	int lives;
	float maxSpeed;
	Vector2 speed;
	textureInfo textureInfo;
};


float spaceShipRotation(player SpaceShip);
void spaceShipMovment(player& SpaceShip);
void screenLimits(player& SpaceShip);
void inItSpaceShip(player& SpaceShip);
void drawSpaceShipTexture(player SpaceShip);
void shoot(bullet bullets[], player SpaceShip, int maxAmmo);
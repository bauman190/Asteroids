#pragma once
#include "raylib.h"

#include "Bullet.h"

struct textureInfo
{
	Texture spaceShipTexture;
	Texture movingShipTexture;
	Rectangle source;
	Rectangle dest;

};

struct player
{
	float x;
	float y;
	int lives;
	float radius;
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
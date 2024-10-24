#pragma once
#include "raylib.h"

#include "Bullet.h"
#include "Circle.h"

struct textureInfo
{
	Texture spaceShipTexture;
	Texture movingShipTexture;
	Rectangle source;
	Rectangle dest;

};

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
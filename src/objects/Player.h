#pragma once
#include "raylib.h"

#include "objects/Bullet.h"
#include "tools/Circle.h"
#include "tools/texture_info.h"


namespace player
{ 
struct player
{
	tools::Circle collider;
	int lives;
	float maxSpeed;
	Vector2 speed;
	tools::textureInfo textureInfo;
	bool immune; 
	int score;
};


float spaceShipRotation(player SpaceShip);
void spaceShipMovment(player& SpaceShip);
void screenLimits(player& SpaceShip);
void inItSpaceShip(player& SpaceShip);
void drawSpaceShipTexture(player SpaceShip);
void shoot(bullet::bullet bullets[], player SpaceShip, int maxAmmo);
void loseLife(player& SpaceShip);
}
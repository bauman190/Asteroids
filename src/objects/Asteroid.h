#pragma once

#include "tools/Circle.h"

struct asteroid
{
	Circle collider;
	Vector2 dir;
	Vector2 speed;
	float initialSpeed;
};

void inItAsteroid(asteroid asteroids[]);

void drawAsteroid(asteroid asteroids[]);

void destroyAsteroid(asteroid& asteroid);

void moveAsteroids(asteroid asteroids[]);
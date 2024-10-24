#pragma once

#include "Circle.h"

struct asteroid
{
	Circle collider;
};

void inItAsteroid(asteroid asteroids[]);

void drawAsteroid(asteroid asteroids[]);

void destroyAsteroid(asteroid& asteroid);
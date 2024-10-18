#pragma once

struct asteroid
{
	float x;
	float y;
	float radius;
};

void inItAsteroid(asteroid& asteroid);

void drawAsteroid(asteroid asteroid);
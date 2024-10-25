#pragma once
#include "raylib.h"

#include "tools/Circle.h"
#include "tools/texture_info.h"

struct asteroid
{
	Circle collider;
	Vector2 dir;
	Vector2 speed;
	float initialSpeed;
	textureInfo textureInfo;
	float angle;
	bool active;
};

void inItAsteroid(asteroid asteroids[]);

void drawAsteroidCollider(asteroid asteroids[]);

void destroyAsteroid(asteroid& asteroid);

void moveAsteroids(asteroid asteroids[]);

void drawAsteroid(asteroid asteroids[]);

void unloadAsteroidsTexture(asteroid asteroids[]);
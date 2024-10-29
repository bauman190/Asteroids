#pragma once
#include "raylib.h"

#include "tools/Circle.h"
#include "tools/texture_info.h"

namespace aster
{

	enum size
	{
		small,
		medium,
		big
	};

struct asteroid
{
	tools::Circle collider;
	Vector2 dir;
	Vector2 speed;
	float initialSpeed;
	tools::textureInfo textureInfo;
	float angle;
	bool active;
	size size;
};

asteroid inItAsteroid(float speed, float radius);

void drawAsteroidCollider(asteroid& asteroids);

void destroyAsteroid(asteroid& asteroid);

void moveAsteroid(asteroid& asteroids);

void drawAsteroid(asteroid& asteroids);

void unloadAsteroidsTexture(asteroid& asteroids);

void restartAsteroid(asteroid &asteroids);

void increasSpeed(asteroid& asteroid);
}
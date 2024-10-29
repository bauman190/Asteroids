#pragma once
#include "raylib.h"

#include "tools/circle.h"
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

asteroid inItAsteroid(size size);

void drawAsteroidCollider(asteroid& asteroids);

void moveAsteroid(asteroid& asteroids);

void drawAsteroid(asteroid& asteroids);

void unloadAsteroidsTexture(asteroid& asteroids);

size randomSize();

}
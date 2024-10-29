#include "objects/Asteroid.h"

#include "raylib.h"
#include <cmath>

aster::asteroid aster::inItAsteroid(float speed, float radius)
{
	aster::asteroid asteroid;
	int randN;
	Texture asteroidTexture = LoadTexture("res/asteroid.png");

		randN = GetRandomValue(0, 1);
		if (randN == 0)
		{
			randN = GetRandomValue(0, 1);
			asteroid.collider.pos.x = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
			if (randN == 0)
			{
				asteroid.collider.pos.y = 0;
			}
			else
			{
				asteroid.collider.pos.y = static_cast<float>(GetScreenHeight());
			}
		}
		else
		{
			randN = GetRandomValue(0, 1);
			if (randN == 0)
			{
				asteroid.collider.pos.x = 0;
			}
			else
			{
				asteroid.collider.pos.x = static_cast<float>(GetScreenWidth());
			}
			asteroid.collider.pos.y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
		}
		asteroid.collider.radius = radius;

		asteroid.dir.x = GetRandomValue(0, GetScreenWidth()) - asteroid.collider.pos.x;
		asteroid.dir.y = GetRandomValue(0, GetScreenHeight()) - asteroid.collider.pos.y;
		float magnitud = static_cast<float>(sqrt(asteroid.dir.x * asteroid.dir.x + asteroid.dir.y * asteroid.dir.y));
		asteroid.dir.x /= magnitud;
		asteroid.dir.y /= magnitud;
		asteroid.initialSpeed = speed;

		asteroid.textureInfo.texture = asteroidTexture;
		asteroid.textureInfo.source.x = 0;
		asteroid.textureInfo.source.y = 0;
		asteroid.textureInfo.source.height = static_cast<float>(asteroid.textureInfo.texture.height);
		asteroid.textureInfo.source.width = static_cast<float>(asteroid.textureInfo.texture.width);
		asteroid.textureInfo.dest.width = asteroid.collider.radius * 2;
		asteroid.textureInfo.dest.height = asteroid.collider.radius * 2;
		asteroid.textureInfo.dest.x = asteroid.collider.pos.x;
		asteroid.textureInfo.dest.y = asteroid.collider.pos.y;
		asteroid.angle = static_cast<float>(GetRandomValue(0, 359));
		asteroid.active = true;
		asteroid.size = aster::medium;

	return asteroid;
}

void aster::drawAsteroidCollider(asteroid& asteroids)
{
	DrawCircle(static_cast<int>(asteroids.collider.pos.x), static_cast<int>(asteroids.collider.pos.y), asteroids.collider.radius, RED);	
}

void aster::destroyAsteroid(asteroid& asteroid)
{
	asteroid.collider.pos.x = -20;
	asteroid.collider.pos.y = -20;
	asteroid.dir = { 0,0 };
	asteroid.active = false;
}

void aster::moveAsteroid(asteroid& asteroids)
{
		if (asteroids.active)
		{
			asteroids.collider.pos.x += asteroids.dir.x * asteroids.initialSpeed * GetFrameTime();
			asteroids.collider.pos.y += asteroids.dir.y * asteroids.initialSpeed * GetFrameTime();
			asteroids.textureInfo.dest.x = asteroids.collider.pos.x;
			asteroids.textureInfo.dest.y = asteroids.collider.pos.y;

			if (asteroids.collider.pos.x > GetScreenWidth())
			{
				asteroids.collider.pos.x = 0 + asteroids.collider.radius;
			}
			else if (asteroids.collider.pos.x < 0)
			{
				asteroids.collider.pos.x = static_cast<float>(GetScreenWidth()) - asteroids.collider.radius;
			}
			else if (asteroids.collider.pos.y > GetScreenHeight())
			{
				asteroids.collider.pos.y = 0 + asteroids.collider.radius;
			}
			else if (asteroids.collider.pos.y < 0)
			{
				asteroids.collider.pos.y = static_cast<float>(GetScreenHeight()) - asteroids.collider.radius;
			}

		}
}


void aster::drawAsteroid(asteroid& asteroids)
{
		if (asteroids.active)
		{
			DrawTexturePro(asteroids.textureInfo.texture,
				asteroids.textureInfo.source,
				asteroids.textureInfo.dest,
				{ asteroids.textureInfo.dest.width / 2, asteroids.textureInfo.dest.height / 2 },
				asteroids.angle,
				WHITE);
		}	
	
}

void aster::unloadAsteroidsTexture(asteroid& asteroids)
{
		UnloadTexture(asteroids.textureInfo.texture);	
}


void aster::restartAsteroid(asteroid& asteroids)
{
	int randN = GetRandomValue(0, 1);
	if (randN == 0)
	{
		randN = GetRandomValue(0, 1);
		asteroids.collider.pos.x = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
		if (randN == 0)
		{
			asteroids.collider.pos.y = 0;
		}
		else
		{
			asteroids.collider.pos.y = static_cast<float>(GetScreenHeight());
		}
	}
	else
	{
		randN = GetRandomValue(0, 1);
		if (randN == 0)
		{
			asteroids.collider.pos.x = 0;
		}
		else
		{
			asteroids.collider.pos.x = static_cast<float>(GetScreenWidth());
		}
		asteroids.collider.pos.y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
	}
	asteroids.dir.x = GetRandomValue(0, GetScreenWidth()) - asteroids.collider.pos.x;
	asteroids.dir.y = GetRandomValue(0, GetScreenHeight()) - asteroids.collider.pos.y;
	float magnitud = static_cast<float>(sqrt(asteroids.dir.x * asteroids.dir.x + asteroids.dir.y * asteroids.dir.y));
	asteroids.dir.x /= magnitud;
	asteroids.dir.y /= magnitud;
	asteroids.angle = static_cast<float>(GetRandomValue(0, 359));
	asteroids.active = true;
}

void aster::increasSpeed(asteroid& asteroid)
{
	asteroid.initialSpeed += 10.0f;
}

#include "objects/Asteroid.h"

#include "raylib.h"
#include <cmath>

void asteroid::inItAsteroid(asteroid& asteroids, float speed, float radius)
{
	int randN;
	Texture asteroidTexture = LoadTexture("res/asteroid.png");

		randN = GetRandomValue(0, 1);
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
		asteroids.collider.radius = radius;

		asteroids.dir.x = GetRandomValue(0, GetScreenWidth()) - asteroids.collider.pos.x;
		asteroids.dir.y = GetRandomValue(0, GetScreenHeight()) - asteroids.collider.pos.y;
		float magnitud = static_cast<float>(sqrt(asteroids.dir.x * asteroids.dir.x + asteroids.dir.y * asteroids.dir.y));
		asteroids.dir.x /= magnitud;
		asteroids.dir.y /= magnitud;
		asteroids.initialSpeed = speed;

		asteroids.textureInfo.texture = asteroidTexture;
		asteroids.textureInfo.source.x = 0;
		asteroids.textureInfo.source.y = 0;
		asteroids.textureInfo.source.height = static_cast<float>(asteroids.textureInfo.texture.height);
		asteroids.textureInfo.source.width = static_cast<float>(asteroids.textureInfo.texture.width);
		asteroids.textureInfo.dest.width = asteroids.collider.radius * 2;
		asteroids.textureInfo.dest.height = asteroids.collider.radius * 2;
		asteroids.textureInfo.dest.x = asteroids.collider.pos.x;
		asteroids.textureInfo.dest.y = asteroids.collider.pos.y;
		asteroids.angle = static_cast<float>(GetRandomValue(0, 359));
		asteroids.active = true;
		
}

void asteroid::drawAsteroidCollider(asteroid asteroids)
{
	DrawCircle(static_cast<int>(asteroids.collider.pos.x), static_cast<int>(asteroids.collider.pos.y), asteroids.collider.radius, RED);	
}

void asteroid::destroyAsteroid(asteroid& asteroid)
{
	asteroid.collider.pos.x = -20;
	asteroid.collider.pos.y = -20;
	asteroid.dir = { 0,0 };
	asteroid.active = false;
}

void asteroid::moveAsteroid(asteroid& asteroids)
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


void asteroid::drawAsteroid(asteroid asteroids)
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

void asteroid::unloadAsteroidsTexture(asteroid& asteroids)
{
		UnloadTexture(asteroids.textureInfo.texture);	
}


void asteroid::restartAsteroid(asteroid& asteroids)
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

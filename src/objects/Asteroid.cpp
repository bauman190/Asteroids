#include "objects/Asteroid.h"

#include "raylib.h"
#include <cmath>


extern const int asteroidsAmount = 10;

void asteroid::inItAsteroid(asteroid asteroids[])
{
	int randN;
	Texture asteroidTexture = LoadTexture("res/asteroid.png");

	for (int  i = 0; i < asteroidsAmount; i++)
	{
		randN = GetRandomValue(0, 1);
		if (randN == 0)
		{
			randN = GetRandomValue(0, 1);
			asteroids[i].collider.pos.x = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
			if (randN == 0)
			{
				asteroids[i].collider.pos.y = 0;
			}
			else
			{
				asteroids[i].collider.pos.y = static_cast<float>(GetScreenHeight());
			}
		}
		else
		{
			randN = GetRandomValue(0, 1);
			if (randN == 0)
			{
				asteroids[i].collider.pos.x = 0;
			}
			else
			{
				asteroids[i].collider.pos.x = static_cast<float>(GetScreenWidth());
			}
			asteroids[i].collider.pos.y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
		}
		asteroids[i].collider.radius = 20;

		asteroids[i].dir.x = GetRandomValue(-GetScreenWidth(), GetScreenWidth()) - asteroids[i].collider.pos.x;
		asteroids[i].dir.y = GetRandomValue(-GetScreenHeight(), GetScreenHeight()) - asteroids[i].collider.pos.y;
		float magnitud = static_cast<float>(sqrt(asteroids[i].dir.x * asteroids[i].dir.x + asteroids[i].dir.y * asteroids[i].dir.y));
		asteroids[i].dir.x /= magnitud;
		asteroids[i].dir.y /= magnitud;
		asteroids[i].initialSpeed = 200.0f;

		asteroids[i].textureInfo.texture = asteroidTexture;
		asteroids[i].textureInfo.source.x = 0;
		asteroids[i].textureInfo.source.y = 0;
		asteroids[i].textureInfo.source.height = static_cast<float>(asteroids[i].textureInfo.texture.height);
		asteroids[i].textureInfo.source.width = static_cast<float>(asteroids[i].textureInfo.texture.width);
		asteroids[i].textureInfo.dest.width = asteroids[i].collider.radius * 2;//static_cast<float>(asteroids[i].textureInfo.texture.width * 3);
		asteroids[i].textureInfo.dest.height = asteroids[i].collider.radius * 2;//static_cast<float>(asteroids[i].textureInfo.texture.height * 3);
		asteroids[i].textureInfo.dest.x = asteroids[i].collider.pos.x;
		asteroids[i].textureInfo.dest.y = asteroids[i].collider.pos.y;
		asteroids[i].angle = static_cast<float>(GetRandomValue(0, 359));
		asteroids[i].active = true;
	}
	
}

void asteroid::drawAsteroidCollider(asteroid asteroids[])
{
	for (int i = 0; i < asteroidsAmount; i++)
	{
		DrawCircle(static_cast<int>(asteroids[i].collider.pos.x), static_cast<int>(asteroids[i].collider.pos.y), asteroids[i].collider.radius, RED);
	}
}

void asteroid::destroyAsteroid(asteroid& asteroid)
{
	asteroid.collider.pos.x = -20;
	asteroid.collider.pos.y = -20;
	asteroid.dir = { 0,0 };
	asteroid.active = false;
}

void asteroid::moveAsteroids(asteroid asteroids[])
{
	for (int i = 0; i < asteroidsAmount; i++)
	{
		if (asteroids[i].active)
		{
			asteroids[i].collider.pos.x += asteroids[i].dir.x * asteroids[i].initialSpeed * GetFrameTime();
			asteroids[i].collider.pos.y += asteroids[i].dir.y * asteroids[i].initialSpeed * GetFrameTime();
			asteroids[i].textureInfo.dest.x = asteroids[i].collider.pos.x;
			asteroids[i].textureInfo.dest.y = asteroids[i].collider.pos.y;

			if (asteroids[i].collider.pos.x > GetScreenWidth())
			{
				asteroids[i].collider.pos.x = 0 + asteroids[i].collider.radius;
			}
			else if (asteroids[i].collider.pos.x < 0)
			{
				asteroids[i].collider.pos.x = static_cast<float>(GetScreenWidth()) - asteroids[i].collider.radius;
			}
			else if (asteroids[i].collider.pos.y > GetScreenHeight())
			{
				asteroids[i].collider.pos.y = 0 + asteroids[i].collider.radius;
			}
			else if (asteroids[i].collider.pos.y < 0)
			{
				asteroids[i].collider.pos.y = static_cast<float>(GetScreenHeight()) - asteroids[i].collider.radius;
			}

		}
	}
}


void asteroid::drawAsteroid(asteroid asteroids[])
{
	for (int i = 0; i < asteroidsAmount; i++)
	{
		
		if (asteroids[i].active)
		{
			DrawTexturePro(asteroids[i].textureInfo.texture,
				asteroids[i].textureInfo.source,
				asteroids[i].textureInfo.dest,
				{ asteroids[i].textureInfo.dest.width / 2, asteroids[i].textureInfo.dest.height / 2 },
				asteroids[i].angle,
				WHITE);
		}	
	}
}

void asteroid::unloadAsteroidsTexture(asteroid asteroids[])
{
	for (int i = 0; i < asteroidsAmount; i++)
	{
		UnloadTexture(asteroids[i].textureInfo.texture);
	}
}


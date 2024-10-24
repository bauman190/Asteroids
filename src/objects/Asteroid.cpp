#include "objects/Asteroid.h"

#include "raylib.h"
#include <cmath>


extern const int asteroidsAmount = 10;

void inItAsteroid(asteroid asteroids[])
{
	int randN;

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
	}
	
}

void drawAsteroid(asteroid asteroids[])
{
	for (int i = 0; i < asteroidsAmount; i++)
	{
		DrawCircle(static_cast<int>(asteroids[i].collider.pos.x), static_cast<int>(asteroids[i].collider.pos.y), asteroids[i].collider.radius, RED);
	}
}

void destroyAsteroid(asteroid& asteroid)
{
	asteroid.collider.pos.x = -20;
	asteroid.collider.pos.y = -20;
	asteroid.dir = { 0,0 };
}

void moveAsteroids(asteroid asteroids[])
{
	for (int i = 0; i < asteroidsAmount; i++)
	{
		if (asteroids[i].collider.pos.x != -20 || asteroids[i].collider.pos.y != -20)
		{
			asteroids[i].collider.pos.x += asteroids[i].dir.x * asteroids[i].initialSpeed * GetFrameTime();
			asteroids[i].collider.pos.y += asteroids[i].dir.y * asteroids[i].initialSpeed * GetFrameTime();

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
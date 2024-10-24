#include "Asteroid.h"

#include "raylib.h"


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
}
#include "Asteroid.h"

#include "raylib.h"


extern const int asteroidsAmount = 10;

void inItAsteroid(asteroid asteroids[])
{
	for (int  i = 0; i < asteroidsAmount; i++)
	{
		asteroids[i].collider.pos.x = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
		asteroids[i].collider.pos.y = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
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
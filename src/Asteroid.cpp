#include "Asteroid.h"

#include "raylib.h"


void inItAsteroid(asteroid& asteroid)
{
	asteroid.x = static_cast<float>(GetScreenWidth() / 3);
	asteroid.y = static_cast<float>(GetScreenHeight() / 3);
	asteroid.radius = 20;
}

void drawAsteroid(asteroid asteroid)
{
	DrawCircle(static_cast<int>(asteroid.x), static_cast<int>(asteroid.y), asteroid.radius, RED);

}
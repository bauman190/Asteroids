#include "Gameplay.h"

#include "raylib.h"

#include "Player.h"
#include "Asteroid.h"
#include "math.h"
#include "Bullet.h"
#include "Circle.h"

static player spaceShip;

static Texture space;

const int asteroidsAmount = 10;

static asteroid asteroids[asteroidsAmount];

static const int maxAmmo = 10;

static bullet bullets[maxAmmo];

bool colitionCirCir(Circle circle1, Circle circle2);

void bulletColition(bullet bullets[], asteroid asterois[]);


void inItGamePlay()
{
	inItSpaceShip(spaceShip);
	inItAsteroid(asteroids);
	inItBullets(bullets, maxAmmo);
	space = LoadTexture("res/space.png");
}

void checkImputGamePlay()
{
	spaceShipMovment(spaceShip);
	shoot(bullets, spaceShip, maxAmmo);
}

void updateGamePlay()
{
	screenLimits(spaceShip);
	spaceShipRotation(spaceShip);
	bulletsMovment(bullets, maxAmmo);
	distroyBullets(bullets, maxAmmo);
	bulletColition(bullets, asteroids);
}

void drawDEBUG()
{
	DrawCircle(static_cast<int>(spaceShip.collider.pos.x), static_cast<int>(spaceShip.collider.pos.y), spaceShip.collider.radius, WHITE);
	drawAsteroid(asteroids);
	drawBulletsColider(bullets, maxAmmo);
	for (int i = 0; i < asteroidsAmount; i++)
	{
		if (colitionCirCir(spaceShip.collider, asteroids[i].collider))
		{
			DrawText("TRUE", 0, 0, 40, RED);
		}
	}
}

void drawGamePlay()
{
	DrawTexture(space, 0, 0, WHITE);
	drawSpaceShipTexture(spaceShip);
	drawBullet(bullets, maxAmmo);
#ifdef _DEBUG
	drawDEBUG();
#endif // _DEBUG
}

void unloadTextures()
{
	UnloadTexture(spaceShip.textureInfo.spaceShipTexture);
	UnloadTexture(spaceShip.textureInfo.movingShipTexture);
}

bool colitionCirCir(Circle circle1, Circle circle2)
{
	float distance = static_cast<float>(sqrt(pow(circle1.pos.x - circle2.pos.x, 2) + pow(circle1.pos.y - circle2.pos.y, 2)));
	if (distance <= circle1.radius + circle2.radius)
	{
		return true;
	}
	return false;
}


void bulletColition(bullet bulletss[], asteroid asteroidss[])
{
	for (int i = 0; i < maxAmmo; i++)
	{
		if (bulletss[i].collider.pos.x != - 1 && bulletss[i].collider.pos.y != -1)
		{
			for (int j = 0; j < asteroidsAmount; j++)
			{
				if (colitionCirCir(bulletss[i].collider, asteroidss[j].collider))
				{
					destroyAsteroid(asteroidss[j]);
					bulletss[i].collider.pos.x = -1;
					bulletss[i].collider.pos.y = -1;
					bulletss[i].dir = { 0,0 };
				}
			}
		}
	}
}



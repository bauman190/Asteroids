#include "Gameplay.h"

#include "raylib.h"

#include "Player.h"
#include "Asteroid.h"
#include "math.h"
#include "Bullet.h"

static player spaceShip;

static Texture space;

static asteroid ast;

static const int maxAmmo = 10;

static bullet bullets[maxAmmo];

bool colitionCirCir(player SpaceShip, asteroid asteroid);


void inItGamePlay()
{
	inItSpaceShip(spaceShip);
	inItAsteroid(ast);
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
}

void drawGamePlay()
{
	DrawTexture(space, 0, 0, WHITE);
	drawSpaceShipTexture(spaceShip);
	drawBullet(bullets, maxAmmo);
#ifdef _DEBUG
	DrawCircle(static_cast<int>(spaceShip.x), static_cast<int>(spaceShip.y), spaceShip.radius, WHITE);
	drawAsteroid(ast);
	drawBulletsColider(bullets, spaceShip.maxAmmo);
	if (colitionCirCir(spaceShip, ast ))
	{
		DrawText("TRUE", 0, 0, 40, RED);
	}
#endif // _DEBUG

}

void unloadTextures()
{
	UnloadTexture(spaceShip.textureInfo.spaceShipTexture);
	UnloadTexture(spaceShip.textureInfo.movingShipTexture);
}

bool colitionCirCir(player SpaceShip, asteroid asteroid)
{
	float distance = static_cast<float>(sqrt(pow(SpaceShip.x - asteroid.x, 2) + pow(SpaceShip.y - asteroid.y, 2)));
	if (distance <= SpaceShip.radius + asteroid.radius)
	{
		return true;
	}
	return false;
}


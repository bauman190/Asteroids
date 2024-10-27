#include "Gameplay.h"

#include "raylib.h"
#include <cmath>

#include "objects/Player.h"
#include "objects/Asteroid.h"
#include "objects/Bullet.h"
#include "tools/Circle.h"

static  player::player spaceShip;

static Texture space;

const int asteroidsAmount = 10;

static asteroid::asteroid asteroids[asteroidsAmount];

static const int maxAmmo = 10;

static bullet::bullet bullets[maxAmmo];

static float timer = 0.0f;

static bool colitionCirCir(tools::Circle circle1, tools::Circle circle2);

static void bulletColition(bullet::bullet bullets[]);

static bool collitionPlayerAsteroid();


void scenes::inItGamePlay()
{
	player::inItSpaceShip(spaceShip);
	asteroid::inItAsteroid(asteroids);
	bullet::inItBullets(bullets, maxAmmo);
	space = LoadTexture("res/space.png");
}

void scenes::checkImputGamePlay()
{
	player::spaceShipMovment(spaceShip);
	player::shoot(bullets, spaceShip, maxAmmo);
	
}

void scenes::updateGamePlay()
{
	player::screenLimits(spaceShip);
	player::spaceShipRotation(spaceShip);
	bullet::bulletsMovment(bullets, maxAmmo);
	bullet::distroyBullets(bullets, maxAmmo);
	asteroid::moveAsteroids(asteroids);

	if (!spaceShip.immune && collitionPlayerAsteroid())
	{
		player::loseLife(spaceShip);
		spaceShip.immune = true;
		timer = 0.0f;
	}

	if (spaceShip.immune)
	{
		timer += GetFrameTime();
	}

	if (timer >= 2)
	{
		spaceShip.immune = false;
		timer = 0;
	}
	bulletColition(bullets);
}

#ifdef _DEBUG
void drawDEBUG()
{
	DrawCircle(static_cast<int>(spaceShip.collider.pos.x), static_cast<int>(spaceShip.collider.pos.y), spaceShip.collider.radius, WHITE);
	asteroid::drawAsteroidCollider(asteroids);
	bullet::drawBulletsColider(bullets, maxAmmo);
	for (int i = 0; i < asteroidsAmount; i++)
	{
		if (colitionCirCir(spaceShip.collider, asteroids[i].collider))
		{
			DrawText("TRUE", 0, 0, 40, RED);
		}
	}
	DrawText(TextFormat("Lives: %02i", spaceShip.lives), 20, 20, 40, BLUE);
}
#endif // _DEBUG

void scenes::drawGamePlay()
{
	DrawTexture(space, 0, 0, WHITE);
	player::drawSpaceShipTexture(spaceShip);
	bullet::drawBullet(bullets, maxAmmo);
	asteroid::drawAsteroid(asteroids);

#ifdef _DEBUG
	drawDEBUG();
#endif // _DEBUG
}

void scenes::unloadGamePlayTextures()
{
	UnloadTexture(spaceShip.textureInfo.texture);
	UnloadTexture(spaceShip.textureInfo.alternativeTexture);
	UnloadTexture(space);
	asteroid::unloadAsteroidsTexture(asteroids);

}

static bool colitionCirCir(tools::Circle circle1, tools::Circle circle2)
{
	float distance = static_cast<float>(sqrt(pow(circle1.pos.x - circle2.pos.x, 2) + pow(circle1.pos.y - circle2.pos.y, 2)));
	if (distance <= circle1.radius + circle2.radius)
	{
		return true;
	}
	return false;
}


static void bulletColition(bullet::bullet bulletss[])
{
	for (int i = 0; i < maxAmmo; i++)
	{
		if (bulletss[i].active)
		{
			for (int j = 0; j < asteroidsAmount; j++)
			{
				if (colitionCirCir(bulletss[i].collider, asteroids[j].collider))
				{
					asteroid::destroyAsteroid(asteroids[j]);
					bulletss[i].collider.pos.x = -1;
					bulletss[i].collider.pos.y = -1;
					bulletss[i].dir = { 0,0 };
					bulletss[i].active = false;
				}
			}
		}
	}
}

static bool collitionPlayerAsteroid()
{
	bool colided = false;

	for (int i = 0; i < asteroidsAmount; i++)
	{
		if (asteroids[i].active)
		{
			colided = colitionCirCir(spaceShip.collider, asteroids[i].collider);
			if (colided)
			{
				return true;
			}
		}
	}
	return false;
}



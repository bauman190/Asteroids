#include "Gameplay.h"

#include "raylib.h"
#include <cmath>

#include "objects/Player.h"
#include "objects/Asteroid.h"
#include "objects/Bullet.h"
#include "tools/Circle.h"

static  player::player spaceShip;

static Texture space;

static const int bigAsteroidsAmount = 4;

static const int midAsteroidsAmount = bigAsteroidsAmount * 2;

static const int smallAsteroidsAmount = midAsteroidsAmount * 2;

static asteroid::asteroid midAsteroids[midAsteroidsAmount];

static asteroid::asteroid bigAsteroids[bigAsteroidsAmount];

static asteroid::asteroid smallAsteroids[smallAsteroidsAmount];

static const int maxAmmo = 10;

static bullet::bullet bullets[maxAmmo];

static float timer = 0.0f;

static bool colitionCirCir(tools::Circle circle1, tools::Circle circle2);

static void bulletColition(bullet::bullet bulletss[]);

static bool collitionPlayerAsteroid();

static void inItAllAsteroids();

static void moveAllAsteroids();

static void drawAllAsteroids();

static void restartAllasteroids();

static bool checkAsteroidActive();

static void restartAllasteroids();

static void increasAllAsteroidsSpeed();

void scenes::inItGamePlay()
{
	player::inItSpaceShip(spaceShip);
	inItAllAsteroids();
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
	moveAllAsteroids();

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

	if (!checkAsteroidActive())
	{
		restartAllasteroids();
		increasAllAsteroidsSpeed();
	}

	bulletColition(bullets);
}

#ifdef _DEBUG
void drawDEBUG()
{
	DrawCircle(static_cast<int>(spaceShip.collider.pos.x), static_cast<int>(spaceShip.collider.pos.y), spaceShip.collider.radius, WHITE);
	for (int i = 0; i < smallAsteroidsAmount; i++)
	{
		asteroid::drawAsteroidCollider(smallAsteroids[i]);
		if (i < midAsteroidsAmount && midAsteroids[i].active)
		{
			asteroid::drawAsteroidCollider(midAsteroids[i]);
		}
		if (i < bigAsteroidsAmount && bigAsteroids[i].active)
		{
			asteroid::drawAsteroidCollider(bigAsteroids[i]);
		}
		if (colitionCirCir(spaceShip.collider, smallAsteroids[i].collider) || 
			colitionCirCir(spaceShip.collider, midAsteroids[i].collider) || 
			colitionCirCir(spaceShip.collider, bigAsteroids[i].collider))
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
	drawAllAsteroids();

#ifdef _DEBUG
	drawDEBUG();
#endif // _DEBUG
}

void scenes::unloadGamePlayTextures()
{
	UnloadTexture(spaceShip.textureInfo.texture);
	UnloadTexture(spaceShip.textureInfo.alternativeTexture);
	UnloadTexture(space);
	for (int i = 0; i < smallAsteroidsAmount; i++)
	{
		asteroid::unloadAsteroidsTexture(smallAsteroids[i]);
		if (i < midAsteroidsAmount)
		{
			asteroid::unloadAsteroidsTexture(midAsteroids[i]);
		}
		if (i < bigAsteroidsAmount)
		{
			asteroid::unloadAsteroidsTexture(bigAsteroids[i]);
		}
	}
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
			for (int j = 0; j < smallAsteroidsAmount; j++)
			{
				if (colitionCirCir(bulletss[i].collider, smallAsteroids[j].collider))
				{
					asteroid::destroyAsteroid(smallAsteroids[j]);
					bulletss[i].collider.pos.x = -1;
					bulletss[i].collider.pos.y = -1;
					bulletss[i].dir = { 0,0 };
					bulletss[i].active = false;
				}
			}
		}
	}
	for (int i = 0; i < maxAmmo; i++)
	{
		if (bulletss[i].active)
		{
			for (int j = 0; j < midAsteroidsAmount; j++)
			{
				if (colitionCirCir(bulletss[i].collider, midAsteroids[j].collider))
				{
					asteroid::destroyAsteroid(midAsteroids[j]);
					bulletss[i].collider.pos.x = -1;
					bulletss[i].collider.pos.y = -1;
					bulletss[i].dir = { 0,0 };
					bulletss[i].active = false;
				}
			}
		}
	}
	for (int i = 0; i < maxAmmo; i++)
	{
		if (bulletss[i].active)
		{
			for (int j = 0; j < bigAsteroidsAmount; j++)
			{
				if (colitionCirCir(bulletss[i].collider, bigAsteroids[j].collider))
				{
					asteroid::destroyAsteroid(bigAsteroids[j]);
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

	for (int i = 0; i < smallAsteroidsAmount; i++)
	{
		if (smallAsteroids[i].active)
		{
			colided = colitionCirCir(spaceShip.collider, smallAsteroids[i].collider);
			if (colided)
			{
				return true;
			}
		}
	}

	for (int i = 0; i < midAsteroidsAmount; i++)
	{
		if (midAsteroids[i].active)
		{
			colided = colitionCirCir(spaceShip.collider, midAsteroids[i].collider);
			if (colided)
			{
				return true;
			}
		}
	}
	for (int i = 0; i < bigAsteroidsAmount; i++)
	{
		colided = colitionCirCir(spaceShip.collider, bigAsteroids[i].collider);
		if (colided)
		{
			return true;
		}
	}
	return false;
}

static void inItAllAsteroids()
{
	float speed = 75.0f;
	float radius = 15.0f;
	for (int i = 0; i < smallAsteroidsAmount; i++)
	{	
			asteroid::inItAsteroid(smallAsteroids[i], speed, radius);	
			if (i % 2 == 0)
			{
				asteroid::destroyAsteroid(smallAsteroids[i]);
			}
	}
	speed = 30.0f;
	radius = 25.0f;

	for (int i = 0; i < midAsteroidsAmount; i++)
	{
		asteroid::inItAsteroid(midAsteroids[i], speed, radius);
		if (i % 2 == 0)
		{
			asteroid::destroyAsteroid(midAsteroids[i]);
		}
	}

	speed = 20.0f;
	radius = 35.0f;
	for (int i = 0; i < bigAsteroidsAmount; i++)
	{
		asteroid::inItAsteroid(bigAsteroids[i], speed, radius);
	}

}

static void moveAllAsteroids()
{
	for (int i = 0; i < smallAsteroidsAmount; i++)
	{
		if (smallAsteroids[i].active)
		{
			asteroid::moveAsteroid(smallAsteroids[i]);
		}
		if ( i < midAsteroidsAmount && midAsteroids[i].active)
		{
			asteroid::moveAsteroid(midAsteroids[i]);
		}
		if (i < bigAsteroidsAmount && bigAsteroids[i].active)
		{
			asteroid::moveAsteroid(bigAsteroids[i]);
		}
	}
}


static void drawAllAsteroids()
{
	for (int i = 0; i < smallAsteroidsAmount; i++)
	{
		if (smallAsteroids[i].active)
		{
			asteroid::drawAsteroid(smallAsteroids[i]);
		}
		if (i < midAsteroidsAmount && midAsteroids[i].active)
		{
			asteroid::drawAsteroid(midAsteroids[i]);
		}
		if (i < bigAsteroidsAmount && bigAsteroids[i].active)
		{
			asteroid::drawAsteroid(bigAsteroids[i]);
		}
	}
}

static void restartAllasteroids()
{
	for (int i = 0; i < smallAsteroidsAmount; i++)
	{
		asteroid::restartAsteroid(smallAsteroids[i]);

		if (i < midAsteroidsAmount)
		{
			asteroid::restartAsteroid(midAsteroids[i]);
		}
		if (i < bigAsteroidsAmount)
		{
			asteroid::restartAsteroid(bigAsteroids[i]);
		}
	}
}

static bool checkAsteroidActive()
{
	for (int i = 0; i < smallAsteroidsAmount; i++)
	{
		if (smallAsteroids[i].active)
		{
			return true;
		}
		if (i < midAsteroidsAmount)
		{
			if (midAsteroids[i].active)
			{
				return true;
			}
		}
		if (i < bigAsteroidsAmount)
		{
			if (bigAsteroids[i].active)
			{
				return true;
			}
		}
	}
	return false;
}

static void increasAllAsteroidsSpeed()
{
	float smallMaxSpeed = 100.0f;
	float midMaxSpeed = 50.0f;
	float bigMaxSpeed = 30.0f;
	for (int i = 0; i < smallAsteroidsAmount; i++)
	{
		if (smallAsteroids[i].initialSpeed < smallMaxSpeed)
		{
			asteroid::increasSpeed(smallAsteroids[i]);
		}
		if (i < midAsteroidsAmount && midAsteroids[i].initialSpeed < midMaxSpeed)
		{
			asteroid::increasSpeed(midAsteroids[i]);
		}
		if ((i < bigAsteroidsAmount && bigAsteroids[i].initialSpeed < bigMaxSpeed))
		{
			asteroid::increasSpeed(midAsteroids[i]);
		}
	}
}
#include "Gameplay.h"

#include "raylib.h"
#include <cmath>
#include <list>

#include "objects/Player.h"
#include "objects/Asteroid.h"
#include "objects/Bullet.h"
#include "tools/Circle.h"

static  player::player spaceShip;

static Texture space;

static std::list<aster::asteroid> asteroids;

static const int maxAmmo = 10;

static bullet::bullet bullets[maxAmmo];

static float timer = 0.0f;

static bool colitionCirCir(tools::Circle circle1, tools::Circle circle2);

static void bulletColition(bullet::bullet bulletss[]);

static bool collitionPlayerAsteroid();

static void inItAllAsteroids();

static void moveAllAsteroids();

static void drawAllAsteroids();

//static void restartAllasteroids();

//static bool checkAsteroidActive();

//static void restartAllasteroids();

//static void increasAllAsteroidsSpeed();

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
	bulletColition(bullets);
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

	/*/if (!checkAsteroidActive())
	{
		//restartAllasteroids();
		increasAllAsteroidsSpeed();
	}*/
}

#ifdef _DEBUG
void drawDEBUG()
{
	DrawCircle(static_cast<int>(spaceShip.collider.pos.x), static_cast<int>(spaceShip.collider.pos.y), spaceShip.collider.radius, WHITE);
	for (auto it = asteroids.begin(); it != asteroids.end(); ++it)
	{
		aster::drawAsteroidCollider(*it);
		if (colitionCirCir(spaceShip.collider, it->collider)) 
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
	for (auto it = asteroids.begin(); it != asteroids.end(); ++it)
	{
		aster::unloadAsteroidsTexture(*it);
	}
}

static bool colitionCirCir(tools::Circle circle1, tools::Circle circle2)
{
	float distance = static_cast<float>(sqrt(pow(circle1.pos.x - circle2.pos.x, 2) + pow(circle1.pos.y - circle2.pos.y, 2)));

	return distance <= circle1.radius + circle2.radius;
}

/*/static void splitAsteroid(asteroid::asteroid& asteroid, asteroid::asteroid smallerAsteroids[], int smallerCount)
{
	int count = 0;
	for (int i = 0; i < smallerCount && count < 2; i++)
	{
		if (!smallerAsteroids[i].active)
		{
			count++;
			asteroid::restartAsteroid(smallerAsteroids[i]);
			smallerAsteroids[i].collider.pos.x = asteroid.collider.pos.x;
			smallerAsteroids[i].collider.pos.y = asteroid.collider.pos.y;
		}
	}
}*/


static void bulletColition(bullet::bullet bulletss[])
{
	for (int i = 0; i < maxAmmo; i++)
	{
		if (bulletss[i].active)
		{
			for (auto it = asteroids.begin(); it != asteroids.end(); it++)
			{
				if (colitionCirCir(bulletss[i].collider, it->collider))
				{
					bulletss[i].collider.pos.x = -1;
					bulletss[i].collider.pos.y = -1;
					bulletss[i].dir = { 0,0 };
					bulletss[i].active = false;
					it = asteroids.erase(it);
					break;
				}
			}
		}	
	}
	
}

static bool collitionPlayerAsteroid()
{
	bool colided = false;

	for (auto it = asteroids.begin(); it != asteroids.end(); ++it)
	{
			colided = colitionCirCir(spaceShip.collider, it->collider);
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
	int asteroidsToCreate = 15;
	for (int i = 0; i < asteroidsToCreate; i++)
	{	
	
		asteroids.push_back(aster::inItAsteroid(speed, radius));
			

	}
	/*speed = 30.0f;
	radius = 25.0f;

	for (int i = 0; i < midAsteroidsAmount; i++)
	{
		
		if (i < 4)
		{
			asteroid::inItAsteroid(midAsteroids[i], speed, radius);
			asteroid::destroyAsteroid(midAsteroids[i]);
		}
	}

	speed = 20.0f;
	radius = 35.0f;
	for (int i = 0; i < bigAsteroidsAmount; i++)
	{
		asteroid::inItAsteroid(bigAsteroids[i], speed, radius);
		asteroid::destroyAsteroid(bigAsteroids[i]);
	}
	*/
}

static void moveAllAsteroids()
{
	for (auto it = asteroids.begin(); it != asteroids.end(); ++it)
	{
		aster::moveAsteroid(*it);
	}
}




static void drawAllAsteroids()
{
	for (auto it = asteroids.begin(); it != asteroids.end(); ++it)
	{
		aster::drawAsteroid(*it);
	}
}

/*/static void restartAllasteroids()
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
}*/

/*/static bool checkAsteroidActive()
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
}*/

/*/static void increasAllAsteroidsSpeed()
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
}*/
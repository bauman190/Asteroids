#include "Gameplay.h"

#include "raylib.h"
#include <cmath>
#include <list>

#include "objects/Player.h"
#include "objects/Asteroid.h"
#include "objects/Bullet.h"
#include "tools/Circle.h"
#include "pause.h"

scenes::inGameScene inGameStatus = scenes::Game;

static  player::player spaceShip;

static Texture space;

static std::list<aster::asteroid> asteroids;

static const int maxAmmo = 10;

static int maxAsteroidsOnScreen = 25;

static bullet::bullet bullets[maxAmmo];

static float timer = 0.0f;

static bool colitionCirCir(tools::Circle circle1, tools::Circle circle2);

static void bulletColition(bullet::bullet bulletss[]);

static bool collitionPlayerAsteroid();

static void inItAllAsteroids();

static void moveAllAsteroids();

static void drawAllAsteroids();

static void clearAsteroids()
{
	asteroids.clear();
}

void scenes::inItGamePlay()
{
	player::inItSpaceShip(spaceShip);
	inItPause();
	clearAsteroids();
	inItAllAsteroids();
	bullet::inItBullets(bullets, maxAmmo);
	space = LoadTexture("res/space.png");
}

void scenes::checkImputGamePlay()
{
	switch (inGameStatus)
	{
	case scenes::Game:
		player::spaceShipMovment(spaceShip);
		player::shoot(bullets, spaceShip, maxAmmo);
		if (IsKeyPressed(KEY_P))
		{
			inGameStatus = Pause;
		}
		break;
	case scenes::Pause:
		scenes::inputPause();
		break;
	default:
		break;
	}
}

void scenes::updateGamePlay()
{
	switch (inGameStatus)
	{
	case scenes::Game:
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

		if (asteroids.empty())
		{
			inItAllAsteroids();
			maxAsteroidsOnScreen += 3;
		}
		break;
	case scenes::Pause:
		break;
	default:
		break;
	}
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
	switch (inGameStatus)
	{
	case scenes::Game:
		DrawTexture(space, 0, 0, WHITE);
		player::drawSpaceShipTexture(spaceShip);
		bullet::drawBullet(bullets, maxAmmo);
		drawAllAsteroids();
#ifdef _DEBUG
		drawDEBUG();
#endif // _DEBUG
		break;
	case scenes::Pause:
		DrawTexture(space, 0, 0, WHITE);
		player::drawSpaceShipTexture(spaceShip);
		bullet::drawBullet(bullets, maxAmmo);
		drawAllAsteroids();
		scenes::drawPause();
		break;
	default:
		break;
	}
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

static void splitAsteroid(aster::asteroid& asteroid)
{
	if (asteroid.size == aster::big)
	{
		asteroids.push_back(aster::inItAsteroid(aster::medium));
		asteroids.push_back(aster::inItAsteroid(aster::medium));
	}
	else if (asteroid.size == aster::medium)
	{
		asteroids.push_back(aster::inItAsteroid(aster::small));
		asteroids.push_back(aster::inItAsteroid(aster::small));
	}
	else
	{
		return;
	}
	std::list<aster::asteroid>::iterator it = asteroids.end();
	it--;
	it->collider.pos.x = asteroid.collider.pos.x;
	it->collider.pos.y = asteroid.collider.pos.y;
	it--;
	it->collider.pos.x = asteroid.collider.pos.x;
	it->collider.pos.y = asteroid.collider.pos.y;
}


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
					splitAsteroid(*it);
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
	int asteroidsToCreate = maxAsteroidsOnScreen;
	aster::size size;
	for (int i = 0; i < asteroidsToCreate; i++)
	{		
		size = aster::randomSize();
		asteroids.push_back(aster::inItAsteroid(size));	
	}
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



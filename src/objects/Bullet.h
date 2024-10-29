#pragma once
#include "raylib.h"

#include "tools/circle.h"

namespace bullet
{ 

struct bullet
{
	tools::Circle collider;
	Vector2 dir;
	Vector2 speed;
	Texture texture;
	Vector2 initalSpeed = { 400, 400 };
	bool active;
};

void bulletsMovment(bullet bullets[], int maxAmmo);
void distroyBullets(bullet bullets[], int maxAmmo);
void drawBullet(bullet bullets[], int maxAmmo);
void drawBulletsColider(bullet bullets[], int maxAmmo);
void inItBullets(bullet bullets[], int maxAmmo);
void unloadBulletsTextures(bullet bullets[], int maxAmmo);
}
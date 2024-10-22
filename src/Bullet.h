#pragma once
#include "raylib.h"

struct bullet
{
	float x;
	float y;
	float radius;
	Vector2 dir;
	Vector2 speed;
	Texture texture;
	Vector2 initalSpeed = { 400, 400 };
};

void bulletsMovment(bullet bullets[], int maxAmmo);
void distroyBullets(bullet bullets[], int maxAmmo);
void drawBulletsColider(bullet bullets[], int maxAmmo);
void drawBullet(bullet bullets[], int maxAmmo);
void inItBullets(bullet bullets[], int maxAmmo);
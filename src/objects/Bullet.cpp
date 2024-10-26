#include "objects/Bullet.h"

#include <cmath>

void bullet::bulletsMovment(bullet bullets[], int maxAmmo)
{
	for (int i = 0; i < maxAmmo; i++)
	{
		if (bullets[i].active)
		{
			bullets[i].speed.x = bullets[i].dir.x;
			bullets[i].speed.y = bullets[i].dir.y;
			bullets[i].collider.pos.x += bullets[i].speed.x * GetFrameTime() * bullets[i].initalSpeed.x;
			bullets[i].collider.pos.y += bullets[i].speed.y * GetFrameTime() * bullets[i].initalSpeed.y;
		}
	}
}

void bullet::distroyBullets(bullet bullets[], int maxAmmo)
{
	for (int i = 0; i < maxAmmo; i++)
	{
		if (bullets[i].collider.pos.x > GetScreenWidth() || bullets[i].collider.pos.y > GetScreenHeight() || bullets[i].collider.pos.x < 0 || bullets[i].collider.pos.y < 0)
		{
			bullets[i].collider.pos.x = -1;
			bullets[i].collider.pos.y = -1;
			bullets[i].dir = { 0,0 };
			bullets[i].active = false;
		}
	}
}

void bullet::drawBullet(bullet bullets[], int maxAmmo)
{
	for (int i = 0; i < maxAmmo; i++)
	{
		DrawTexture(bullets[i].texture, 
			static_cast<int>(bullets[i].collider.pos.x - bullets[i].texture.width / 2), 
			static_cast<int>(bullets[i].collider.pos.y - bullets[i].texture.height / 2),
			WHITE);
	}
}

void bullet::drawBulletsColider(bullet bullets[], int maxAmmo)
{
	for (int i = 0; i < maxAmmo; i++)
	{
		DrawCircle(static_cast<int>(bullets[i].collider.pos.x), static_cast<int>(bullets[i].collider.pos.y), bullets[i].collider.radius, BLUE);
	}
}

void bullet::inItBullets(bullet bullets[], int maxAmmo)
{
	for (int i = 0; i < maxAmmo; i++)
	{
		bullets[i].collider.pos.x = -1;
		bullets[i].collider.pos.y = -1;
		bullets[i].collider.radius = 2;
		bullets[i].dir = { 0,0 };
		bullets[i].texture = LoadTexture("res/Bullet.png");
		bullets[i].active = false;
	}
}

void bullet::unloadBulletsTextures(bullet bullets[], int maxAmmo)
{
	for (int i = 0; i < maxAmmo; i++)
	{
		UnloadTexture(bullets[i].texture);
	}
}
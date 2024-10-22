#include "Bullet.h"

#include "math.h"

void bulletsMovment(bullet bullets[], int maxAmmo)
{
	for (int i = 0; i < maxAmmo; i++)
	{
		if (bullets[i].x != -1 && bullets[i].y != -1)
		{
			bullets[i].speed.x = bullets[i].dir.x;
			bullets[i].speed.y = bullets[i].dir.y;
			bullets[i].x += bullets[i].speed.x * GetFrameTime() * bullets[i].initalSpeed.x;
			bullets[i].y += bullets[i].speed.y * GetFrameTime() * bullets[i].initalSpeed.y;
		}
	}
}

void distroyBullets(bullet bullets[], int maxAmmo)
{
	for (int i = 0; i < maxAmmo; i++)
	{
		if (bullets[i].x > GetScreenWidth() || bullets[i].y > GetScreenHeight() || bullets[i].x < 0 || bullets[i].y < 0)
		{
			bullets[i].x = -1;
			bullets[i].y = -1;
			bullets[i].dir = { 0,0 };
		}
	}
}

void drawBullet(bullet bullets[], int maxAmmo)
{
	for (int i = 0; i < maxAmmo; i++)
	{
		DrawTexture(bullets[i].texture, static_cast<int>(bullets[i].x - bullets[i].texture.width / 2), static_cast<int>(bullets[i].y - bullets[i].texture.height / 2), WHITE);
	}
}

void drawBulletsColider(bullet bullets[], int maxAmmo)
{
	for (int i = 0; i < maxAmmo; i++)
	{
		DrawCircle(static_cast<int>(bullets[i].x), static_cast<int>(bullets[i].y), 2, BLUE);
	}
}

void inItBullets(bullet bullets[], int maxAmmo)
{
	for (int i = 0; i < maxAmmo; i++)
	{
		bullets[i].x = -1;
		bullets[i].y = -1;
		bullets[i].dir = { 0,0 };
		bullets[i].texture = LoadTexture("res/Bullet.png");
	}
}
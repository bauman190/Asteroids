#include "objects/player.h"

#include <cmath>

#include "raylib.h"

#include "bullet.h"

static Sound bulletSound;

static float convertToDegree(float angle)
{
	return angle * (180 / PI);
}

float  player::spaceShipRotation(player SpaceShip)
{
	Vector2 distance;
	distance.x = GetMousePosition().x - SpaceShip.collider.pos.x;
	distance.y = GetMousePosition().y - SpaceShip.collider.pos.y;

	float angle = static_cast<float>(convertToDegree(atan2(distance.y , distance.x)));

	return angle;
}

void  player::spaceShipMovment(player& SpaceShip)
{
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		Vector2 direction = { static_cast<float>(GetMouseX() - SpaceShip.collider.pos.x) , static_cast<float>(GetMouseY() - SpaceShip.collider.pos.y) };
		float magnitud = static_cast<float>(sqrt(direction.x * direction.x + direction.y * direction.y));
		direction.x /= magnitud;
		direction.y /= magnitud;

		SpaceShip.speed.x += direction.x;
		SpaceShip.speed.y += direction.y;
	}
	float currentSpeed = static_cast<float>(sqrt(SpaceShip.speed.x * SpaceShip.speed.x + SpaceShip.speed.y * SpaceShip.speed.y));

		if (currentSpeed > SpaceShip.maxSpeed)
		{
			SpaceShip.speed.x = (SpaceShip.speed.x / currentSpeed) * SpaceShip.maxSpeed;
			SpaceShip.speed.y = (SpaceShip.speed.y / currentSpeed) * SpaceShip.maxSpeed;
		}
		SpaceShip.collider.pos.x = SpaceShip.collider.pos.x + SpaceShip.speed.x * GetFrameTime();
		SpaceShip.collider.pos.y = SpaceShip.collider.pos.y + SpaceShip.speed.y * GetFrameTime();
		SpaceShip.textureInfo.dest.x = SpaceShip.collider.pos.x;
		SpaceShip.textureInfo.dest.y = SpaceShip.collider.pos.y;
}

void  player::screenLimits(player& SpaceShip)
{
	if (SpaceShip.collider.pos.x >= GetScreenWidth())
	{
		SpaceShip.collider.pos.x = 0 + SpaceShip.collider.radius;
	}
	else if (SpaceShip.collider.pos.x <= 0)
	{
		SpaceShip.collider.pos.x = static_cast<float>(GetScreenWidth() - SpaceShip.collider.radius);
	}
	else if (SpaceShip.collider.pos.y <= 0)
	{
		SpaceShip.collider.pos.y = static_cast<float>(GetScreenHeight() - SpaceShip.collider.radius);
	}
	else if (SpaceShip.collider.pos.y >= GetScreenHeight())
	{
		SpaceShip.collider.pos.y = 0 + SpaceShip.collider.radius;
	}
}

void  player::inItSpaceShip(player& SpaceShip)
{
	SpaceShip.collider.pos.x = static_cast<float>(GetScreenWidth() / 2);
	SpaceShip.collider.pos.y = static_cast<float>(GetScreenHeight() / 2);
	SpaceShip.speed = { 0.0f, 0.0f };
	SpaceShip.collider.radius = 15;
	SpaceShip.textureInfo.texture = LoadTexture("res/Nave2.png");
	SpaceShip.textureInfo.alternativeTexture = LoadTexture("res/Nave1.png");
	SpaceShip.textureInfo.source.x = 0;
	SpaceShip.textureInfo.source.y = 0;
	SpaceShip.textureInfo.source.height = static_cast<float>(SpaceShip.textureInfo.texture.height);
	SpaceShip.textureInfo.source.width = static_cast<float>(SpaceShip.textureInfo.texture.width);
	SpaceShip.textureInfo.dest.width = static_cast<float>(SpaceShip.textureInfo.texture.width * 3);
	SpaceShip.textureInfo.dest.height = static_cast<float>(SpaceShip.textureInfo.texture.height * 3);
	SpaceShip.textureInfo.dest.x = SpaceShip.collider.pos.x;
	SpaceShip.textureInfo.dest.y = SpaceShip.collider.pos.y;
	SpaceShip.maxSpeed = 250.0f;
	SpaceShip.immune = false;
	SpaceShip.lives = 3;
	SpaceShip.score = 0;
	bulletSound = LoadSound("res/Laser_Shoot.wav");
}

void  player::drawSpaceShipTexture(player SpaceShip)
{
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		DrawTexturePro(SpaceShip.textureInfo.alternativeTexture,
			SpaceShip.textureInfo.source, 
			SpaceShip.textureInfo.dest,
			{ SpaceShip.textureInfo.dest.width / 2, SpaceShip.textureInfo.dest.height / 2 },
			spaceShipRotation(SpaceShip), 
			WHITE);
	}
	else if (!IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		DrawTexturePro(SpaceShip.textureInfo.texture,
			SpaceShip.textureInfo.source,
			SpaceShip.textureInfo.dest,
			{ SpaceShip.textureInfo.dest.width / 2, SpaceShip.textureInfo.dest.height / 2 },
			spaceShipRotation(SpaceShip),
			WHITE);
	}
	if (SpaceShip.immune)
	{		
		DrawCircle(static_cast<int>(SpaceShip.collider.pos.x), static_cast<int>(SpaceShip.collider.pos.y), SpaceShip.collider.radius * 2, ColorAlpha(BLUE, 0.3f));
	}
}

void  player::shoot(bullet::bullet bullets[], player SpaceShip, int maxAmmo)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		for (int i = 0; i < maxAmmo; i++)
		{
			if (!bullets[i].active)
			{
				bullets[i].collider.pos.x = SpaceShip.collider.pos.x;
				bullets[i].collider.pos.y = SpaceShip.collider.pos.y;
				if (bullets[i].dir.x == 0 && bullets[i].dir.y == 0)
				{
					bullets[i].dir = { static_cast<float>(GetMouseX() - bullets[i].collider.pos.x), static_cast<float>(GetMouseY() - bullets[i].collider.pos.y) };
					float magnitud = static_cast<float>(sqrt(bullets[i].dir.x * bullets[i].dir.x + bullets[i].dir.y * bullets[i].dir.y));
					bullets[i].dir.x /= magnitud;
					bullets[i].dir.y /= magnitud;
					bullets[i].active = true;
					PlaySound(bulletSound);
				}
				break;
			}
		}
	}
}

void player::loseLife(player& SpaceShip)
{
	SpaceShip.lives--;
}
#include "Player.h"

#include "raylib.h"

#include "math.h"
#include "Bullet.h"


float spaceShipRotation(player SpaceShip)
{
	float angle = static_cast<float>(atan2(GetMousePosition().y - SpaceShip.y , GetMousePosition().x - SpaceShip.x) * (180 / PI));

	return angle;
}

void spaceShipMovment(player& SpaceShip)
{
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		Vector2 direction = { static_cast<float>(GetMouseX() - SpaceShip.x) , static_cast<float>(GetMouseY() - SpaceShip.y) };
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
		SpaceShip.x = SpaceShip.x + SpaceShip.speed.x * GetFrameTime();
		SpaceShip.y = SpaceShip.y + SpaceShip.speed.y * GetFrameTime();
		SpaceShip.textureInfo.dest.x = SpaceShip.x;
		SpaceShip.textureInfo.dest.y = SpaceShip.y;
}

void screenLimits(player& SpaceShip)
{
	if (SpaceShip.x >= GetScreenWidth())
	{
		SpaceShip.x = 0 + SpaceShip.radius;
	}
	else if (SpaceShip.x <= 0)
	{
		SpaceShip.x = static_cast<float>(GetScreenWidth() - SpaceShip.radius);
	}
	else if (SpaceShip.y <= 0)
	{
		SpaceShip.y = static_cast<float>(GetScreenHeight() - SpaceShip.radius);
	}
	else if (SpaceShip.y >= GetScreenHeight())
	{
		SpaceShip.y = 0 + SpaceShip.radius;
	}
}

void inItSpaceShip(player& SpaceShip)
{
	SpaceShip.x = static_cast<float>(GetScreenWidth() / 2);
	SpaceShip.y = static_cast<float>(GetScreenHeight() / 2);
	SpaceShip.speed = { 0.0f, 0.0f };
	SpaceShip.radius = 15;
	SpaceShip.textureInfo.spaceShipTexture = LoadTexture("res/Nave2.png");
	SpaceShip.textureInfo.movingShipTexture = LoadTexture("res/Nave1.png");
	SpaceShip.textureInfo.source.x = 0;
	SpaceShip.textureInfo.source.y = 0;
	SpaceShip.textureInfo.source.height = static_cast<float>(SpaceShip.textureInfo.spaceShipTexture.height);
	SpaceShip.textureInfo.source.width = static_cast<float>(SpaceShip.textureInfo.spaceShipTexture.width);
	SpaceShip.textureInfo.dest.width = static_cast<float>(SpaceShip.textureInfo.spaceShipTexture.width * 3);
	SpaceShip.textureInfo.dest.height = static_cast<float>(SpaceShip.textureInfo.spaceShipTexture.height * 3);
	SpaceShip.textureInfo.dest.x = SpaceShip.x;
	SpaceShip.textureInfo.dest.y = SpaceShip.y;
	SpaceShip.maxSpeed = 250.0f;
}

void drawSpaceShipTexture(player SpaceShip)
{
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		DrawTexturePro(SpaceShip.textureInfo.movingShipTexture,
			SpaceShip.textureInfo.source, 
			SpaceShip.textureInfo.dest,
			{ SpaceShip.textureInfo.dest.width / 2, SpaceShip.textureInfo.dest.height / 2 },
			spaceShipRotation(SpaceShip), 
			WHITE);
	}
	else if (!IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		DrawTexturePro(SpaceShip.textureInfo.spaceShipTexture, 
			SpaceShip.textureInfo.source,
			SpaceShip.textureInfo.dest,
			{ SpaceShip.textureInfo.dest.width / 2, SpaceShip.textureInfo.dest.height / 2 },
			spaceShipRotation(SpaceShip),
			WHITE);
	}
}

void shoot(bullet bullets[], player SpaceShip, int maxAmmo)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		for (int i = 0; i < maxAmmo; i++)
		{
			if (bullets[i].x == -1 && bullets[i].y == -1)
			{
				bullets[i].x = SpaceShip.x;
				bullets[i].y = SpaceShip.y;
				if (bullets[i].dir.x == 0 && bullets[i].dir.y == 0)
				{
					bullets[i].dir = { static_cast<float>(GetMouseX() - bullets[i].x), static_cast<float>(GetMouseY() - bullets[i].y) };
					float magnitud = static_cast<float>(sqrt(bullets[i].dir.x * bullets[i].dir.x + bullets[i].dir.y * bullets[i].dir.y));
					bullets[i].dir.x /= magnitud;
					bullets[i].dir.y /= magnitud;
				}
				break;
			}
		}
	}
}
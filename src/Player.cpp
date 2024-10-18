#include "Player.h"

#include "raylib.h"

#include "math.h"


float shipRotation(player player)
{
	float angle = static_cast<float>(atan2(GetMousePosition().y - player.y , GetMousePosition().x - player.x) * (180 / PI));

	return angle;
}

void playerMovment(player& player)
{
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		Vector2 direction = { static_cast<float>(GetMouseX() - player.x) , static_cast<float>(GetMouseY() - player.y) };
		float magnitud = static_cast<float>(sqrt(direction.x * direction.x + direction.y * direction.y));
		direction.x /= magnitud;
		direction.y /= magnitud;

		player.speed.x += direction.x;
		player.speed.y += direction.y;
	}
	float currentSpeed = static_cast<float>(sqrt(player.speed.x * player.speed.x + player.speed.y * player.speed.y));

		if (currentSpeed > player.maxSpeed)
		{
			player.speed.x = (player.speed.x / currentSpeed) * player.maxSpeed;
			player.speed.y = (player.speed.y / currentSpeed) * player.maxSpeed;
		}
	player.x = player.x + player.speed.x * GetFrameTime();
	player.y = player.y + player.speed.y * GetFrameTime();
}

void screenLimits(player& player)
{
	if (player.x >= GetScreenWidth())
	{
		player.x = 0 + 10;
	}
	else if (player.x <= 0)
	{
		player.x = static_cast<float>(GetScreenWidth() - 10);
	}
	else if (player.y <= 0)
	{
		player.y = static_cast<float>(GetScreenHeight() - 10);
	}
	else if (player.y >= GetScreenHeight())
	{
		player.y = 0 + 10;
	}
}

void inItPlayer(player& player)
{
	player.x = static_cast<float>(GetScreenWidth() / 2);
	player.y = static_cast<float>(GetScreenHeight() / 2);
	player.speed = { 0.0f, 0.0f };
	player.texture = LoadTexture("res/Nave2.png");
	player.textureProperties.x = 0;
	player.textureProperties.y = 0;
	player.textureProperties.height = static_cast<float>(player.texture.height);
	player.textureProperties.width = static_cast<float>(player.texture.width);
	player.texturePos.width = static_cast<float>(player.texture.width * 3);
	player.texturePos.height = static_cast<float>(player.texture.height * 3);
	player.texturePos.x = player.x;
	player.texturePos.y = player.y;
	player.maxSpeed = 250.0f;
}
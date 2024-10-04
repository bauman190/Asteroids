#include "Player.h"

#include "raylib.h"



void moveUp(player& player)
{
	if (IsKeyDown(KEY_W))
	{
		player.y -= player.speed * GetFrameTime();
	}
}
void moveDown(player& player)
{
	if (IsKeyDown(KEY_S))
	{
		player.y += player.speed * GetFrameTime();
	}
}
void moveLeft(player& player)
{
	if (IsKeyDown(KEY_A))
	{
		player.x -= player.speed * GetFrameTime();
	}
}

void moveRight(player& player)
{
	if (IsKeyDown(KEY_D))
	{
		player.x += player.speed * GetFrameTime();
	}
}
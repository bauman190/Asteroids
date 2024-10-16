#include "Gameplay.h"

#include "raylib.h"

#include "Player.h"


static player Player;

void inItGamePlay()
{
	Player.x = static_cast<float>(GetScreenWidth() / 2);
	Player.y = static_cast<float>(GetScreenHeight() / 2);
	Player.speed = 100.0f;

}

void checkImputGamePlay()
{
	moveUp(Player);
	moveDown(Player);
	moveLeft(Player);
	moveRight(Player);
}

void updateGamePlay()
{

}

void drawGamePlay()
{
	DrawCircle(static_cast<int>(Player.x), static_cast<int>(Player.y), 10, WHITE);
}


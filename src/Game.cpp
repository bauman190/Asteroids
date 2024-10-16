#include "Game.h"

#include "raylib.h"

#include "Player.h"

#include "ScreenOptions.h"


void runGame()
{
	const int Width = 1024;
	const int Height = 768;

	//Screen currentScreen;

	InitWindow(Width, Height, "Asteroids");


	player player;
	player.x = static_cast<float>(GetScreenWidth() / 2);
	player.y = static_cast<float>(GetScreenHeight() / 2);
	player.speed = 100.0f;

	while (!WindowShouldClose())
	{
		moveUp(player);
		moveDown(player);
		moveLeft(player);
		moveRight(player);


		BeginDrawing();
		ClearBackground(BLACK);
		DrawCircle(static_cast<int>(player.x), static_cast<int>(player.y), 10, WHITE);
		EndDrawing();
	}

	CloseWindow();

}
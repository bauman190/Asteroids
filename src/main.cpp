#include "raylib.h"

const int Width = 1024;
const int Height = 768;

int main()
{

	InitWindow(Width, Height, "Asteroids");

	while (!WindowShouldClose())
	{



		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();
	}

	CloseWindow();
}
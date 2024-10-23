#include "Game.h"

#include "raylib.h"

#include "Player.h"
#include "ScreenOptions.h"
#include "MainMenu.h"
#include "Gameplay.h"

const int windowWidth = 1024;
const int windowHeight = 768;

Screen currentScreen = MainMenu;

Texture backGround;

float fontScale = 1.3f;

Font textFont;

void inIt();

void checkImput();

void update();

void draw();

void close();

void runGame()
{
	inIt();

	while (!WindowShouldClose())
	{
		checkImput();

		update();

		draw();
	}

	close();
}

void inIt()
{
	InitWindow(windowWidth, windowHeight, "Pong");
	textFont = LoadFont("C:/Users/bauma/OneDrive/Escritorio/impo/facu/fonts/PressStart2P-Regular.ttf");
	inItMainMenu();
	inItGamePlay();
}

void checkImput()
{
	switch (currentScreen)
	{
	case MainMenu:
		checkImputMainMenu();
		break;
	case Gameplay:
		checkImputGamePlay();
		break;
	default:
		break;
	}
}

void update()
{

	switch (currentScreen)
	{
	case MainMenu:
		break;
	case Gameplay:
		updateGamePlay();
		break;
	default:
		break;
	}

}

void draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	switch (currentScreen)
	{
	case MainMenu:
		drawMainMenu();
		break;
	case Gameplay:
		drawGamePlay();
		break;
		
	default:
		break;
	}

	EndDrawing();
}

void close()
{
	unloadTextures();
	UnloadTexture(backGround);
	CloseWindow();
}

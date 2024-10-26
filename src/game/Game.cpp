#include "Game.h"

#include "raylib.h"

#include "objects/Player.h"
#include "scene/ScreenOptions.h"
#include "scene/MainMenu.h"
#include "scene/Gameplay.h"
#include "scene/credits.h"



static const int windowWidth = 1024;
static const int windowHeight = 768;

scenes::Screen currentScreen = scenes::MainMenu;

Texture backGround;


static void inIt();

static void checkImput();

static void update();

static void draw();

static void close();




void game::runGame()
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



static void inIt()
{
	InitWindow(windowWidth, windowHeight, "Pong");
	scenes::inItMainMenu();
	scenes::inItGamePlay();
	scenes::inItCredits();
}

static void checkImput()
{
	switch (currentScreen)
	{
	case scenes::MainMenu:
		scenes::checkImputMainMenu();
		break;
	case scenes::Gameplay:
		scenes::checkImputGamePlay();
		break;
	case scenes::Credits:
		scenes::checkInputCredits();
		break;
	default:
		break;
	}
}

static void update()
{

	switch (currentScreen)
	{
	case scenes::MainMenu:
		break;
	case scenes::Gameplay:
		scenes::updateGamePlay();
		break;
	case scenes::Credits:
		break;
	default:
		break;
	}

}

static void draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	switch (currentScreen)
	{
	case scenes::MainMenu:
		scenes::drawMainMenu();
		break;
	case scenes::Gameplay:
		scenes::drawGamePlay();
		break;
	case scenes::Credits:
		scenes::drawCredits();
		break;
	default:
		break;
	}

	EndDrawing();
}

static void close()
{
	scenes::unloadGamePlayTextures();
	scenes::unloadMianMenuTextures();
	UnloadTexture(backGround);
	CloseWindow();
}

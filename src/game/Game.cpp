#include "Game.h"

#include "raylib.h"

#include "scene/ScreenOptions.h"
#include "scene/MainMenu.h"
#include "scene/Gameplay.h"
#include "scene/credits.h"
#include "scene/how_to_play.h"



static const int windowWidth = 1024;
static const int windowHeight = 768;

scenes::Screen currentScreen = scenes::MainMenu;

Texture backGround;


static void inIt();

static void checkImput();

static void update();

static void draw();

static void close();

bool exitGame = false;



void game::runGame()
{
	inIt();
	while (!WindowShouldClose() && !exitGame)
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
	InitAudioDevice();
	scenes::inItMainMenu();
	scenes::inItGamePlay();
	scenes::inItCredits();
	scenes::inItHowTo();
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
	case scenes::HowToPlay:
		scenes::inputHowTo();
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
		scenes::updateMenu();
		break;
	case scenes::Gameplay:
		scenes::updateGamePlay();
		break;
	case scenes::Credits:
		break;
	case scenes::HowToPlay:
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
	case scenes::HowToPlay:
		scenes::drawHowTo();
		break;
	default:
		break;
	}

	EndDrawing();
}

static void close()
{
	scenes::unloadGamePlay();
	scenes::unloadMianMenu();
	scenes::unloadCreditsTextures();
	scenes::unloadHowTo();
	UnloadTexture(backGround);
	CloseAudioDevice();
	CloseWindow();
}

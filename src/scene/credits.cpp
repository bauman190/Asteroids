#include "scene/credits.h"

#include "raylib.h"

#include "UI/Button.h"
#include "scene/ScreenOptions.h"

extern scenes::Screen currentScreen;

static UI::Button back;

static Texture background;

void scenes::inItCredits()
{
	background = LoadTexture("res/space.png");
	background.width = GetScreenWidth();
	background.height = GetScreenHeight();
	UI::inItButton(back, 100.0f, GetScreenHeight() - 50.0f, LoadTexture("res/Back_on.png"), LoadTexture("res/Back_off.png"));
}

void scenes::drawCredits()
{
	DrawTexture(background, 0, 0, WHITE);
	UI::drawButton(back);
}

void scenes::checkInputCredits()
{
	if (UI::clickButton(back))
	{
		currentScreen = MainMenu;
	}
}

void scenes::unloadCreditsTextures()
{
	UI::unloadButtonTextures(back);
}
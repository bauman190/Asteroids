#include "pause.h"

#include "raylib.h"

#include "UI/button.h"
#include "screen_options.h"
#include "gameplay.h"

extern scenes::inGameScene inGameStatus;
extern scenes::Screen currentScreen;



static UI::Button play;
static UI::Button exit;

void scenes::inItPause()
{
	UI::inItButton(play, static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2), LoadTexture("res/Play_on.png"), LoadTexture("res/Play_off.png"));
	UI::inItButton(exit, static_cast<float>(GetScreenWidth() / 2), play.button.y + play.button.height *2, LoadTexture("res/Exit_on.png"), LoadTexture("res/Exit_off.png"));
}
void scenes::drawPause()
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), ColorAlpha(BLACK, 0.5));
	DrawText("Pause", GetScreenWidth() / 2 - MeasureText("Pause", 150) / 2, static_cast<int>(GetScreenHeight() * 0.2), 150, WHITE);
	UI::drawButton(play);
	UI::drawButton(exit);
}
void scenes::inputPause()
{
	if (UI::clickButton(play))
	{
		inGameStatus = Game;
	}
	if (UI::clickButton(exit))
	{
		inGameStatus = Game;
		inItGamePlay();
		currentScreen = MainMenu;
	}
}

void scenes::unloadPause()
{
	UI::unloadButtonTextures(play);
	UI::unloadButtonTextures(exit);
}
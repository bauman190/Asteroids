#include "game_over.h"

#include "raylib.h"

#include "UI/button.h"
#include "screen_options.h"
#include "gameplay.h"

extern scenes::inGameScene inGameStatus;
extern scenes::Screen currentScreen;

static UI::Button play; 
static UI::Button exit;

void scenes::inItGameOver()
{
	UI::inItButton(play, static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2), LoadTexture("res/Play_on.png"), LoadTexture("res/Play_off.png"));
	UI::inItButton(exit, static_cast<float>(GetScreenWidth() / 2), play.button.y + play.button.height * 2, LoadTexture("res/Exit_on.png"), LoadTexture("res/Exit_off.png"));
}
void scenes::drawGameOver()
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), ColorAlpha(BLACK, 1));
	DrawText("Game Over", GetScreenWidth() / 2 - MeasureText("Game Over", 150) / 2, static_cast<int>(GetScreenHeight() * 0.2), 150, WHITE);
	UI::drawButton(play);
	UI::drawButton(exit);
}
void scenes::inPutGameOver()
{
	if (UI::clickButton(play))
	{
		inGameStatus = Game;
		inItGamePlay();
	}
	if (UI::clickButton(exit))
	{
		inGameStatus = Game;
		inItGamePlay();
		currentScreen = MainMenu;
	}
}

void scenes::unloadGameOver()
{
	UI::unloadButtonTextures(play);
	UI::unloadButtonTextures(exit);
}
#include "MainMenu.h"

#include "raylib.h"

#include "Button.h"
#include "ScreenOptions.h"

extern Screen currentScreen;

extern Texture backGround;

static Button play;

extern Font textFont;

extern float fontScale;


void checkImputMainMenu()
{
	if (clickButton(play))
	{
		currentScreen = Gameplay;
	}
}


void drawMainMenu()
{
	DrawTexture(backGround, 0, 0, WHITE);

	DrawTextEx(textFont, "Play", { play.button.x, play.button.y }, play.button.height, 1.0f, DARKGRAY);
	

	if (onButton(play))
	{
		
		DrawRectangle(static_cast<int>(play.button.x), static_cast<int>(play.button.y), static_cast<int>(play.button.width), static_cast<int>(play.button.height), WHITE);
		DrawTextEx(textFont, "Play", { play.button.x, play.button.y }, play.button.height, 1.0f, LIGHTGRAY);
		
	}

	DrawText("By: Juan Bautista Castignani", 0, static_cast<int>(GetScreenHeight() * 0.95), 25, WHITE);

}

void inItMainMenu()
{
	play.button.width = static_cast<float>(MeasureTextEx(textFont, "Play", static_cast<float>(textFont.glyphs->advanceX * fontScale), 00.0f).x);
	play.button.height = static_cast<float>(textFont.baseSize * fontScale);
	play.button.x = static_cast<float>(GetScreenWidth() / 2 - play.button.width / 2);
	play.button.y = static_cast<float>(GetScreenHeight() / 2);
	backGround = LoadTexture("res/MMBG.png");
	backGround.height = GetScreenHeight();
	backGround.width = GetScreenWidth();
}
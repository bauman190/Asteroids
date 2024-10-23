#include "MainMenu.h"

#include "raylib.h"

#include "Button.h"
#include "ScreenOptions.h"

extern Screen currentScreen;

extern Texture backGround;

static Button play;

extern Font textFont;

extern float fontScale;
;

Color buttonBack = { 0,0,0, 100 };

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

	//DrawText("Asteroids", static_cast<int>(GetScreenWidth() / 2 - MeasureText("Asteroids", 100) / 2), static_cast<int>(GetScreenHeight() * 0.20), 100, WHITE);

	DrawTextEx(textFont, "Play", { play.button.x, play.button.y }, play.button.height, 1.0f, DARKGRAY);
	//DrawText("Play", static_cast<int>(play.button.x), static_cast<int>(play.button.y), static_cast<int>(play.button.height), WHITE);


	if (onButton(play))
	{
		
		DrawRectangle(static_cast<int>(play.button.x), static_cast<int>(play.button.y), static_cast<int>(play.button.width), static_cast<int>(play.button.height), buttonBack);
		DrawTextEx(textFont, "Play", { play.button.x, play.button.y }, play.button.height, 1.0f, LIGHTGRAY);
		//DrawText("Play", static_cast<int>(play.button.x), static_cast<int>(play.button.y), static_cast<int>(play.button.height), BLACK);
	}

	DrawText("By: Juan Bautista Castignani", 0, static_cast<int>(GetScreenHeight() * 0.95), 25, WHITE);

}

void inItMainMenu()
{
	textFont = LoadFont("C:/Users/bauma/OneDrive/Escritorio/impo/facu/fonts/PressStart2P-Regular.ttf");
	play.button.width = static_cast<float>(MeasureTextEx(textFont, "Play", static_cast<float>(textFont.glyphs->advanceX * fontScale), 00.0f).x);
	play.button.height = static_cast<float>(textFont.baseSize * fontScale);
	play.button.x = static_cast<float>(GetScreenWidth() / 2 - play.button.width / 2);
	play.button.y = static_cast<float>(GetScreenHeight() / 2);
	backGround = LoadTexture("res/MMBG.png");
	backGround.height = GetScreenHeight();
	backGround.width = GetScreenWidth();
}
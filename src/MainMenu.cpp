#include "MainMenu.h"

#include "raylib.h"

#include "Button.h"
#include "ScreenOptions.h"

extern Screen currentScreen;

extern Texture backGround;

static Button play;



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

	DrawText("Play", static_cast<int>(play.button.x), static_cast<int>(play.button.y), static_cast<int>(play.button.height), WHITE);

	if (onButton(play))
	{
		DrawRectangle(static_cast<int>(play.button.x), static_cast<int>(play.button.y), static_cast<int>(play.button.width), static_cast<int>(play.button.height), WHITE);
		DrawText("Play", static_cast<int>(play.button.x), static_cast<int>(play.button.y), static_cast<int>(play.button.height), BLACK);
	}

	DrawText("By: Juan Bautista Castignani", 0, static_cast<int>(GetScreenHeight() * 0.95), 25, WHITE);

}

void inItMainMenu()
{
	play.button.x = static_cast<float>(GetScreenWidth() / 2 - MeasureText("Play", 50) / 2);
	play.button.y = static_cast<float>(GetScreenHeight() / 2);
	play.button.width = static_cast<float>(MeasureText("Play", 50));
	play.button.height = 50;
	backGround = LoadTexture("res/MMBG.png");
	backGround.height = GetScreenHeight();
	backGround.width = GetScreenWidth();
}
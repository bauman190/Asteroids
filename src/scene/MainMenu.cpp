#include "MainMenu.h"

#include "raylib.h"

#include "objects/Button.h"
#include "scene/ScreenOptions.h"

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
	
	drawButton(play);	

	DrawText("By: Juan Bautista Castignani", 0, static_cast<int>(GetScreenHeight() * 0.95), 25, WHITE);

}

void inItMainMenu()
{
	play.button.width = 150;
	play.button.height = 50;
	play.button.x = static_cast<float>(GetScreenWidth() / 2 - play.button.width / 2);
	play.button.y = static_cast<float>(GetScreenHeight() / 2);
	play.on = LoadTexture("res/Play_on.png");
	play.off = LoadTexture("res/Play_off.png");
	play.off.width = static_cast<int>(play.button.width);
	play.off.height = static_cast<int>(play.button.height);
	play.on.width = static_cast<int>(play.button.width);
	play.on.height = static_cast<int>(play.button.height);
	backGround = LoadTexture("res/MMBG.png");
	backGround.height = GetScreenHeight();
	backGround.width = GetScreenWidth();
}
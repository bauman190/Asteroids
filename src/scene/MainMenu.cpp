#include "MainMenu.h"

#include "raylib.h"

#include "UI/Button.h"
#include "scene/ScreenOptions.h"

extern scenes::Screen currentScreen;

extern Texture backGround;

static UI::Button play;

static UI::Button credits;



void scenes::checkImputMainMenu()
{
	if (UI::clickButton(play))
	{
		currentScreen = Gameplay;
	}
	if (UI::clickButton(credits))
	{
		currentScreen = Credits;
	}
}


void scenes::drawMainMenu()
{
	DrawTexture(backGround, 0, 0, WHITE);
	
	UI::drawButton(play);
	UI::drawButton(credits);

	DrawText("By: Juan Bautista Castignani", 0, static_cast<int>(GetScreenHeight() * 0.95), 25, WHITE);

}

void scenes::inItMainMenu()
{
	float midScreenX = static_cast<float>(GetScreenWidth() / 2);

	UI::inItButton(play, midScreenX,
		static_cast<float>(GetScreenHeight() / 2), 
		LoadTexture("res/Play_on.png"), 
		LoadTexture("res/Play_off.png"));

	UI::inItButton(credits, midScreenX, 
		play.button.y + play.button.height * 2, 
		LoadTexture("res/Credits_on.png"), 
		LoadTexture("res/Credits_off.png"));

	backGround = LoadTexture("res/MMBG.png");
	backGround.height = GetScreenHeight();
	backGround.width = GetScreenWidth();


}

void scenes::unloadMianMenuTextures()
{
	UnloadTexture(play.off);
	UnloadTexture(play.on);
	UnloadTexture(backGround);
}
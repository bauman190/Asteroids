#include "MainMenu.h"

#include "raylib.h"

#include "UI/Button.h"
#include "scene/ScreenOptions.h"

extern scenes::Screen currentScreen;

extern Texture backGround;

static UI::Button play;

static UI::Button credits;

static UI::Button exit;

extern bool exitGame;

static Music music;

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
	if (UI::clickButton(exit))	
	{
		exitGame = true;
	}
}


void scenes::drawMainMenu()
{
	DrawTexture(backGround, 0, 0, WHITE);
	
	UI::drawButton(play);
	UI::drawButton(credits);
	UI::drawButton(exit);

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

	UI::inItButton(exit, 100, GetScreenHeight() - 50.0f, LoadTexture("res/Exit_on.png"), LoadTexture("res/Exit_off.png"));

	music = LoadMusicStream("res/Asteroids_menu.wav");
	music.looping = true;
	PlayMusicStream(music);
	backGround = LoadTexture("res/MMBG.png");
	backGround.height = GetScreenHeight();
	backGround.width = GetScreenWidth();
}

void scenes::unloadMianMenuTextures()
{
	UI::unloadButtonTextures(play);
	UI::unloadButtonTextures(exit);
	UI::unloadButtonTextures(credits);
	UnloadMusicStream(music);
	UnloadTexture(backGround);
}

void scenes::updateMenu()
{
	UpdateMusicStream(music);
}
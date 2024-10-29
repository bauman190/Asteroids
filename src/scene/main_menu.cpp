#include "main_menu.h"

#include "raylib.h"

#include "UI/button.h"
#include "scene/screen_options.h"
#include "how_to_play.h"

extern scenes::Screen currentScreen;

extern Texture backGround;

static UI::Button play;

static UI::Button credits;

static UI::Button controls;

static UI::Button exit;

extern bool exitGame;

static Music music;

void scenes::checkImputMainMenu()
{
	if (UI::clickButton(play))
	{
		StopMusicStream(music);
		PlayMusicStream(music);
		currentScreen = Gameplay;
	}
	if (UI::clickButton(credits))
	{
		StopMusicStream(music);
		PlayMusicStream(music);
		currentScreen = Credits;
	}
	if (UI::clickButton(controls))
	{
		StopMusicStream(music);
		PlayMusicStream(music);
		currentScreen = HowToPlay;
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
	UI::drawButton(controls);
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

	UI::inItButton(controls, midScreenX,
		credits.button.y + credits.button.height * 2,
		LoadTexture("res/Controls_on.png"),
		LoadTexture("res/Controls_off.png"));

	UI::inItButton(exit, 100, GetScreenHeight() - 50.0f, LoadTexture("res/Exit_on.png"), LoadTexture("res/Exit_off.png"));

	music = LoadMusicStream("res/Asteroids_menu.wav");
	music.looping = true;
	PlayMusicStream(music);
	backGround = LoadTexture("res/MMBG.png");
	backGround.height = GetScreenHeight();
	backGround.width = GetScreenWidth();
}

void scenes::unloadMianMenu()
{
	UI::unloadButtonTextures(play);
	UI::unloadButtonTextures(exit);
	UI::unloadButtonTextures(credits);
	UI::unloadButtonTextures(controls);
	UnloadMusicStream(music);
	UnloadTexture(backGround);
}

void scenes::updateMenu()
{
	UpdateMusicStream(music);
}
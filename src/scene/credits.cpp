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

	int x = GetScreenWidth() / 2 - MeasureText("Credits", 50) / 2;
	int y = static_cast<int>(GetScreenHeight() * 0.2);
	DrawText("Credits", x, y, 50, WHITE);
	y = static_cast<int>(GetScreenHeight() * 0.3);
	x = static_cast<int>(GetScreenWidth() * 0.80 - MeasureText("Art: ", 40) / 2);
	DrawText("Art: ", x, y, 30, WHITE);

	x = static_cast<int>(GetScreenWidth() * 0.20 - MeasureText("Code: ", 40) / 2);
	DrawText("Code: ", x, y, 30, WHITE);

	y = static_cast<int>(GetScreenHeight() * 0.4);
	x = static_cast<int>(GetScreenWidth() * 0.80 - MeasureText("Felipe Garea Berlin", 30) / 2);
	DrawText("Felipe Garea Berlin", x, y, 30, GRAY);

	x = static_cast<int>(GetScreenWidth() * 0.20 - MeasureText("Juan Bautista Castignain", 30) / 2);
	DrawText("Juan Bautista Castignain", x, y, 30, GRAY);

	y = static_cast<int>(GetScreenHeight() * 0.5);
	x = static_cast<int>(GetScreenWidth() * 0.80 - MeasureText("Space Ship, Asteroid", 20) / 2);
	DrawText("Space Ship, Asteroid", x, y, 20, GRAY);

	y = static_cast<int>(GetScreenHeight() * 0.6);
	x = static_cast<int>(GetScreenWidth() * 0.80 - MeasureText("Buttons, Background", 20) / 2);
	DrawText("Buttons, Background", x, y, 20, GRAY);

	y = static_cast<int>(GetScreenHeight() * 0.5);
	x = static_cast<int>(GetScreenWidth() * 0.20 - MeasureText("Music and Sound Efects", 30) / 2);
	DrawText("Music and Sound Efects:", x, y, 30, WHITE);

	y = static_cast<int>(GetScreenHeight() * 0.6);
	x = static_cast<int>(GetScreenWidth() * 0.20 - MeasureText("Juan Bautista Castignain", 30) / 2);
	DrawText("Juan Bautista Castignain", x, y, 30, GRAY);

	
	y = static_cast<int>(GetScreenHeight() * 0.8);
	x = static_cast<int>(GetScreenWidth() * 0.20 - MeasureText("Support Tools:", 30) / 2);
	DrawText("Support Tools:", x, y, 30, WHITE);

	y = static_cast<int>(GetScreenHeight() * 0.9);
	x = static_cast<int>(GetScreenWidth() * 0.20);
	DrawText("Code:Raylib   Art:Aseprite   Music:Bosca Ceoil  Sound Efects:BFCR ", x, y, 20, GRAY);


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
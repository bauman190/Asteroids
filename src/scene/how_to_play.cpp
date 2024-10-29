#include "how_to_play.h"

#include "raylib.h"

#include "UI/button.h"
#include "scene/screen_options.h"

extern scenes::Screen currentScreen;

static UI::Button back;

static Texture background;


void scenes::inItHowTo()
{
	background = LoadTexture("res/space.png");
	background.width = GetScreenWidth();
	background.height = GetScreenHeight();
	UI::inItButton(back, 100.0f, GetScreenHeight() - 50.0f, LoadTexture("res/Back_on.png"), LoadTexture("res/Back_off.png"));
}
void scenes::drawHowTo()
{
	DrawTexture(background, 0, 0, WHITE);
	UI::drawButton(back);

	int x = GetScreenWidth() / 2 - MeasureText("Controls", 50) / 2;
	int y = static_cast<int>(GetScreenHeight() * 0.2);
	DrawText("Controls", x, y, 50, WHITE);

	x = static_cast<int>(GetScreenWidth() * 0.20);
	y = static_cast<int>(GetScreenHeight() * 0.3);
	DrawText("Left Click: Shoot", x, y, 40, WHITE);

	y = static_cast<int>(GetScreenHeight() * 0.4);
	DrawText("Right Click: Move", x, y, 40, WHITE);

	y = static_cast<int>(GetScreenHeight() * 0.5);
	DrawText("P: Pause", x, y, 40, WHITE);

	y = static_cast<int>(GetScreenHeight() * 0.6);
	DrawText("Destroy as much asteroids as yo can!", x, y, 20, WHITE);
}
void scenes::inputHowTo()
{
	if (UI::clickButton(back))
	{
		currentScreen = MainMenu;
	}
}

void scenes::unloadHowTo()
{
	UI::unloadButtonTextures(back);
}


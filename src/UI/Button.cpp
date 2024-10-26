#include "UI/Button.h"

bool UI::clickButton(Button button)
{

	if (CheckCollisionPointRec(GetMousePosition(), button.button) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		return true;
	}
	return false;
}

bool UI::onButton(Button button)
{

	if (CheckCollisionPointRec(GetMousePosition(), button.button))
	{
		return true;
	}
	return false;
}

void UI::drawButton(Button button)
{

	if (CheckCollisionPointRec(GetMousePosition(), button.button))
	{
		DrawTexture(button.on, static_cast<int>(button.button.x), static_cast<int>(button.button.y), WHITE);
	}
	else
	{
		DrawTexture(button.off, static_cast<int>(button.button.x), static_cast<int>(button.button.y), WHITE);
	}
}

void UI::inItButton(Button& button, float x, float y, Texture on, Texture off)
{
	button.button.width = 150;
	button.button.height = 50;
	button.button.x = x - button.button.width / 2;
	button.button.y = y;
	button.on = on; 
	button.off = off; 
	button.off.width = static_cast<int>(button.button.width);
	button.off.height = static_cast<int>(button.button.height);
	button.on.width = static_cast<int>(button.button.width);
	button.on.height = static_cast<int>(button.button.height);


}
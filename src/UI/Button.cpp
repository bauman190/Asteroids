#include "UI/Button.h"

bool clickButton(Button button)
{

	if (CheckCollisionPointRec(GetMousePosition(), button.button) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		return true;
	}
	return false;
}

bool onButton(Button button)
{

	if (CheckCollisionPointRec(GetMousePosition(), button.button))
	{
		return true;
	}
	return false;
}

void drawButton(Button button)
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
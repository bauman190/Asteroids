#include "Button.h"

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

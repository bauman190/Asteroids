#include "Gameplay.h"

#include "raylib.h"

#include "Player.h"


static player Player;

static Texture space;

static Texture otherShip;

void inItGamePlay()
{
	inItPlayer(Player);
	otherShip = LoadTexture("res/Nave1.png");

	space = LoadTexture("res/space.png");
}

void checkImputGamePlay()
{
	playerMovment(Player);
	Player.texturePos.x = Player.x;
	Player.texturePos.y = Player.y;
}

void updateGamePlay()
{
	screenLimits(Player);
	shipRotation(Player);
}

void drawPlayerTexture()
{
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		DrawTexturePro(otherShip, Player.textureProperties, Player.texturePos, { Player.texturePos.width / 2, Player.texturePos.height / 2 }, shipRotation(Player), WHITE);
	}
	else if (!IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		DrawTexturePro(Player.texture, Player.textureProperties, Player.texturePos, { Player.texturePos.width / 2, Player.texturePos.height / 2 }, shipRotation(Player), WHITE);
	}
}

void drawGamePlay()
{
	DrawTexture(space, 0, 0, WHITE);
	drawPlayerTexture();
#ifdef _DEBUG
	DrawCircle(static_cast<int>(Player.x), static_cast<int>(Player.y), 10, WHITE);
#endif // _DEBUG

}

void unloadTextures()
{
	UnloadTexture(Player.texture);
	UnloadTexture(otherShip);
}


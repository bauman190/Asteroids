#include "Gameplay.h"

#include "raylib.h"

#include "Player.h"
#include "Asteroid.h"
#include "math.h"

static player Player;

static Texture space;

static Texture otherShip;

static asteroid ast;

bool colitionCirCir(player player, asteroid asteroid);


void inItGamePlay()
{
	inItPlayer(Player);
	inItAsteroid(ast);
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
	drawAsteroid(ast);
#ifdef _DEBUG
	DrawCircle(static_cast<int>(Player.x), static_cast<int>(Player.y), Player.radius, WHITE);
	if (colitionCirCir(Player, ast ))
	{
		DrawText("TRUE", 0, 0, 10, RED);
	}
#endif // _DEBUG

}

void unloadTextures()
{
	UnloadTexture(Player.texture);
	UnloadTexture(otherShip);
}

bool colitionCirCir(player player, asteroid asteroid)
{
	float distance = static_cast<float>(sqrt(pow(player.x - asteroid.x, 2) + pow(player.y - asteroid.y, 2)));
	if (distance <= player.radius + asteroid.radius)
	{
		return true;
	}
	return false;
}


#include "Gameplay.h"

#include "raylib.h"

#include "Player.h"
#include "Asteroid.h"
#include "math.h"

static player spaceShip;

static Texture space;

static Texture otherShip;

static asteroid ast;

bool colitionCirCir(player SpaceShip, asteroid asteroid);


void inItGamePlay()
{
	inItPlayer(spaceShip);
	inItAsteroid(ast);
	otherShip = LoadTexture("res/Nave1.png");

	space = LoadTexture("res/space.png");
}

void checkImputGamePlay()
{
	playerMovment(spaceShip);
	spaceShip.texturePos.x = spaceShip.x;
	spaceShip.texturePos.y = spaceShip.y;
}

void updateGamePlay()
{
	screenLimits(spaceShip);
	shipRotation(spaceShip);
}

void drawPlayerTexture()
{
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		DrawTexturePro(otherShip, spaceShip.textureProperties, spaceShip.texturePos, { spaceShip.texturePos.width / 2, spaceShip.texturePos.height / 2 }, shipRotation(spaceShip), WHITE);
	}
	else if (!IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		DrawTexturePro(spaceShip.texture, spaceShip.textureProperties, spaceShip.texturePos, { spaceShip.texturePos.width / 2, spaceShip.texturePos.height / 2 }, shipRotation(spaceShip), WHITE);
	}
}

void drawGamePlay()
{
	DrawTexture(space, 0, 0, WHITE);
	drawPlayerTexture();
#ifdef _DEBUG
	DrawCircle(static_cast<int>(spaceShip.x), static_cast<int>(spaceShip.y), spaceShip.radius, WHITE);
	drawAsteroid(ast);
	if (colitionCirCir(spaceShip, ast ))
	{
		DrawText("TRUE", 0, 0, 40, RED);
	}
#endif // _DEBUG

}

void unloadTextures()
{
	UnloadTexture(spaceShip.texture);
	UnloadTexture(otherShip);
}

bool colitionCirCir(player SpaceShip, asteroid asteroid)
{
	float distance = static_cast<float>(sqrt(pow(SpaceShip.x - asteroid.x, 2) + pow(SpaceShip.y - asteroid.y, 2)));
	if (distance <= SpaceShip.radius + asteroid.radius)
	{
		return true;
	}
	return false;
}


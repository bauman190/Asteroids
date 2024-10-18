#include "Gameplay.h"

#include "raylib.h"

#include "Player.h"


static player Player;

static Texture space;

void inItGamePlay()
{
	Player.x = static_cast<float>(GetScreenWidth() / 2);
	Player.y = static_cast<float>(GetScreenHeight() / 2);
	Player.speed = { 0.0f, 0.0f};
	Player.texture = LoadTexture("res/Nave2.png");
	Player.textureProperties.x = 0;
	Player.textureProperties.y = 0;
	Player.textureProperties.height = static_cast<float>(Player.texture.height);
	Player.textureProperties.width = static_cast<float>(Player.texture.width);
	Player.texturePos.width = static_cast<float>(Player.texture.width * 3);
	Player.texturePos.height = static_cast<float>(Player.texture.height * 3);
	Player.texturePos.x = Player.x;
	Player.texturePos.y = Player.y;
	Player.maxSpeed = 250.0f;

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

}

void drawGamePlay()
{
	DrawTexture(space, 0, 0, WHITE);
	DrawTexturePro(Player.texture, Player.textureProperties, Player.texturePos, { Player.texturePos.width / 2, Player.texturePos.height / 2 }, shipRotation(Player), WHITE);
	DrawCircle(static_cast<int>(Player.x), static_cast<int>(Player.y), 10, WHITE);
	shipRotation(Player);
	screenLimits(Player);
}

void unloadTextures()
{
	UnloadTexture(Player.texture);
}

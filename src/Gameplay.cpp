#include "Gameplay.h"

#include "raylib.h"

#include "Player.h"


static player Player;


void inItGamePlay()
{
	Player.x = static_cast<float>(GetScreenWidth() / 2);
	Player.y = static_cast<float>(GetScreenHeight() / 2);
	Player.speed = 100.0f;
	Player.texture = LoadTexture("res/Nave2.png");
	Player.textureProperties.x = 0;
	Player.textureProperties.y = 0;
	Player.textureProperties.height = static_cast<float>(Player.texture.height);
	Player.textureProperties.width = static_cast<float>(Player.texture.width);
	Player.texturePos.width = static_cast<float>(Player.texture.width * 3);
	Player.texturePos.height = static_cast<float>(Player.texture.height * 3);
	Player.texturePos.x = Player.x;
	Player.texturePos.y = Player.y;
}

void checkImputGamePlay()
{
	moveUp(Player);
	moveDown(Player);
	moveLeft(Player);
	moveRight(Player);
	Player.texturePos.x = Player.x;
	Player.texturePos.y = Player.y;
}

/*/void updateGamePlay()
{

}*/

void drawGamePlay()
{
	DrawTexturePro(Player.texture, Player.textureProperties, Player.texturePos, { Player.texturePos.width / 2, Player.texturePos.height / 2 }, 0, WHITE);
	DrawCircle(static_cast<int>(Player.x), static_cast<int>(Player.y), 10, WHITE);
}

void unloadTextures()
{
	UnloadTexture(Player.texture);
}

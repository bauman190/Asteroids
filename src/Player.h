#pragma once


struct player
{
	float x;
	float y;
	int lives;
	float speed;
};

void moveUp(player& player);
void moveDown(player& player);
void moveLeft(player& player);
void moveRight(player& player);
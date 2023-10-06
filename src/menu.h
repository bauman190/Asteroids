#pragma once



enum MenuState
{
	MainMenu,
	Game,
	Exit,
};

struct Buton
{
	float posY;
	float posX;
	int hight;
	int width;
	MenuState state;
};

void changeState(MenuState menuState, Buton buton);
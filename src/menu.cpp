#include "menu.h"
#include "raylib.h"

MenuState changeToGame()
{
	return Game;
}
 
void changeState(MenuState menuState, Buton buton)
{
	switch (menuState)
	{
	case MainMenu:
		
		break;
	case Game:
		break;
	case Exit:
		break;
	default:
		break;
	}
	
}
#include "game.h"

#include "raylib.h"

#include "menu.h"





void runGame() 
{   

    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "Asteriods");

    SetExitKey(KEY_F4);
    Vector2 mousePos = GetMousePosition();

    MenuState menuState = MainMenu;

    static Buton Game;
    Game.posX = screenWidth / 2;
    Game.posY = screenHeight / 2;
    Game.width = 50;
    Game.width = 50;
    Game.state = MenuState::Game;
    
    while (!WindowShouldClose())
    {
        mousePos = GetMousePosition();        

        
        
        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangle(static_cast<int>(Game.posX), static_cast<int>(Game.posY), Game.width, Game.hight, WHITE);
        
        EndDrawing();

    }


    CloseWindow();
}
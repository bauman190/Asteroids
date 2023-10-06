#include "raylib.h"
void main() 
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Asteriods");


    while (!WindowShouldClose())    
    {
        
        BeginDrawing();

        ClearBackground(BLACK);      

        EndDrawing();
        
    }

    
    CloseWindow();
}

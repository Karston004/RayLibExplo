#include "raylib.h"
#include <cmath>  // for cosf, sinf

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    SetTraceLogLevel(LOG_NONE);
    InitWindow(screenWidth, screenHeight, "Triangle Example");

    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        Vector2 center = {400,300};
        // Compute two points on the hexagon's edge (0° and 60°)
        float angle1 = DEG2RAD * 0.0f;
        float angle2 = DEG2RAD * 60.0f;

        Vector2 p1 = { 500,300 };
        Vector2 p2 = { 450,500 };
        Vector2 p3 = { 350,100 };


        DrawTriangle(p1, p2, p3, DARKBLUE);
        DrawCircleV(center, 10, RED);
        DrawCircleV(p1, 10, BLACK);
        DrawCircleV(p2, 10, BLACK);
        DrawCircleV(p3, 10, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
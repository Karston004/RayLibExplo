#include "raylib.h"
#include <cmath>  // for sin, cos
#include <iostream>
int main() {
    SetTraceLogLevel(LOG_NONE);
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Raylib - Hexagon Example");

    SetTargetFPS(60);

    Vector2 center = {screenWidth / 2.0f, screenHeight / 2.0f};
    float radius = 100;
    std::cout << center.x << "," << center.y << std::endl;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw hexagon (filled using triangles)
        for (int i = 0; i < 6; i++) {
            float angle1 = DEG2RAD * (60 * i);
            float angle2 = DEG2RAD * (60 * (i + 1));

            Vector2 p1 = { center.x + radius * (float)cos(angle1), center.y + radius * (float)sin(angle1) };
            Vector2 p2 = { center.x + radius * (float)cos(angle2), center.y + radius * (float)sin(angle2) };

            DrawTriangle(center, p2, p1, DARKBLUE);
        }
        // Optional: draw outline
        for (int i = 0; i < 6; i++) {
            float angle1 = DEG2RAD * (60 * i);
            float angle2 = DEG2RAD * (60 * (i + 1));

            Vector2 p1 = {
                float(center.x + radius * cos(angle1)),
                float(center.y + radius * sin(angle1))
            };
            Vector2 p2 = {
                float(center.x + radius * cos(angle2)),
                float(center.y + radius * sin(angle2))
            };

            DrawLineEx(p1, p2, 5, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
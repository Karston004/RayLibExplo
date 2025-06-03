#include "raylib.h"
#include <cmath>  // for sin, cos

int main() {
    //SetTraceLogLevel(LOG_NONE);
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib - Hexagon Example");

    SetTargetFPS(60);

    Vector2 center = {400, 300};
    float radius = 100;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw hexagon (filled using triangles)
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

            DrawTriangle(center, p1, p2, BLACK);
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

            DrawLineV(p1, p2, DARKBLUE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
#include "../include/resource_dir.h"
#include "../include/cell.h"
#include "raylib.h"
#include <stdio.h>

#define FIXED_TIMESTEP (1.0f / 60.0f)
#define MAX_ACCUMULATOR 0.2f

int main() {
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
  InitWindow(1280, 800, "Hello Raylib");
  SearchAndSetResourceDir("resources");

  Texture wabbit = LoadTexture("wabbit_alpha.png");

  int x = 0;
  int y = 0;
  int xDirection = 1;
  int yDirection = 1;

  float accumulator = 0.0f;

  cell_t cell = create_cell(40, 40, 80, 80);
  cell_t cell2 = create_cell(80, 80, 120, 120);

  while (!WindowShouldClose()) {
    // --- PHYSICS (fixed timestep) ---
    float delta = GetFrameTime();
    if (delta > MAX_ACCUMULATOR)
      delta = MAX_ACCUMULATOR;
    accumulator += delta;

    while (accumulator >= FIXED_TIMESTEP) {
      if (y > 800)
        yDirection = -1;
      if (y < 0)
        yDirection = 1;
      if (x > 1280)
        xDirection = -1;
      if (x < 0)
        xDirection = 1;

      x += xDirection;
      y += yDirection;

      accumulator -= FIXED_TIMESTEP;
    }

    // --- RENDER ---
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Hello Raylib", 200, 200, 20, WHITE);
    DrawCircle(x, y, 30.0f, RED);

    DrawLine(0, 50, 800, 800, BLUE);

    char fps[12];
    sprintf(fps, "%d", GetFPS());
    DrawText(fps, 10, 10, 20, WHITE);

    DrawTexture(wabbit, 400, 200, WHITE);
    draw_fill_cell(&cell);
    draw_cell(&cell2);
    EndDrawing();
  }

  UnloadTexture(wabbit);
  CloseWindow();
  return 0;
}

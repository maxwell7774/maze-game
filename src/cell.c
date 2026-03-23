#include "../include/cell.h"
#include <raylib.h>

cell_t create_cell(int x1, int y1, int x2, int y2) {
  cell_t cell = {
      .has_bottom_wall = true,
      .has_top_wall = true,
      .has_left_wall = true,
      .has_right_wall = true,
      .x1 = x1,
      .x2 = x2,
      .y1 = y1,
      .y2 = y2,
  };

  return cell;
}

void draw_cell(cell_t* cell) {
    if(cell->has_top_wall) DrawLine(cell->x1, cell->y1, cell->x2, cell->y1, WHITE);
    if(cell->has_bottom_wall) DrawLine(cell->x1, cell->y2, cell->x2, cell->y2, WHITE);
    if(cell->has_right_wall) DrawLine(cell->x2, cell->y1, cell->x2, cell->y2, WHITE);
    if(cell->has_left_wall) DrawLine(cell->x1, cell->y1, cell->x1, cell->y2, WHITE);
}

void draw_fill_cell(cell_t* cell) {
    DrawRectangle(cell->x1+5, cell->y1+5, cell->x2-cell->x1-10, cell->y2-cell->y1-10, GREEN);
    draw_cell(cell);
}

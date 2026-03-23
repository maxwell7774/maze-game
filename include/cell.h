#pragma once
#include <stdbool.h>

typedef struct {
        bool has_left_wall;
        bool has_right_wall;
        bool has_top_wall;
        bool has_bottom_wall;
        bool visited;
        int x1;
        int x2;
        int y1;
        int y2;
} cell_t;

cell_t create_cell(int x1, int y1, int x2, int y2);
void draw_cell(cell_t* cell);
void draw_fill_cell(cell_t* cell);

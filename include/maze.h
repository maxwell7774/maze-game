#pragma once

#include "cell.h"

typedef struct {
    int x1;
    int y1;
    int num_rows;
    int num_cols;
    int cell_width;
    int cell_height;
    cell_t** cell_list;
} maze_t;

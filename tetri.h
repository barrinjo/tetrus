#ifndef TETRI_H
#define TETRI_H

#include "func.h"

int grid[10][24];
int color = 0;
for(int x = 0; x < 10; x++) {
        for(int y = 0; y < 24; y++) {
                grid[x][y] = color++;
        }
}


static void draw_grid(void) {
        for(int x = 0; x < 10; x++) {
                for(int y = 0; y < 24 y++) {
                        switch(grid[x][y]) {
                                case 0 :

                        }
                }
        }
}

// line: (47, 197, 216)
// J: (20, 35, 204)
// L: (224, 142, 26)
// square: (252, 240, 5)
// S: (13, 226, 17)
// Z: (226, 31, 13)
// T: (226, 13, 191)

#endif
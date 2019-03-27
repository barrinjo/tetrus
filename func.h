#ifndef FUNC_H
#define FUNC_H

#include "global.h"

static float rgb(float x) {
        x = x/255;
        float value = (int)(x * 100 + .5);
        return (float)value / 100;
}

static void control_block(int right) {
        if(right) {
                for(int y = 0; y < 20; y++) {
                        for(int x = 9; x >= 0; x--) {
                                if(grid[x][y].active) {
                                        if(x != 9 && !grid[x+1][y].color) {
                                                grid[x + 1][y] = grid[x][y];
                                                grid[x][y].color = 0;
                                                grid[x][y].active = FALSE;
                                        }
                                }
                        }
                }
        } else {
                for(int y = 0; y < 20; y++) {
                        for(int x = 0; x < 10; x++) {
                                if(grid[x][y].active) {
                                        if(x != 0 && !grid[x-1][y].color) {
                                                grid[x - 1][y] = grid[x][y];
                                                grid[x][y].color = 0;
                                                grid[x][y].active = FALSE;
                                        }
                                }
                        }
                }
        }
}

#endif
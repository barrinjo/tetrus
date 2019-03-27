#ifndef FUNC_H
#define FUNC_H

#include "global.h"

static void shift_block(int right, int x, int y);

static float rgb(float x) {
        x = x/255;
        float value = (int)(x * 100 + .5);
        return (float)value / 100;
}

static void control_block(int right) {
        struct coord coord[4];
        int i = 0;
        gboolean active_flag = FALSE;
        if(right) {
                for(int y = 0; y < 20; y++) {
                        for(int x = 9; x >= 0; x--) {
                                if(grid[x][y].active) {
                                        coord[i].x = x;
                                        coord[i++].y = y;
                                        if(x == 9) {
                                                active_flag = TRUE;
                                        } else if(!grid[x+1][y].active && grid[x+1][y].color) {
                                                active_flag = TRUE;
                                        }
                                }
                        }
                }
                if(!active_flag) {
                        for(int j = 0; j < 4; j++) {
                                shift_block(1, coord[j].x, coord[j].y);
                        }
                }
        } else {
                for(int y = 0; y < 20; y++) {
                        for(int x = 0; x < 10; x++) {
                                if(grid[x][y].active) {
                                        coord[i].x = x;
                                        coord[i++].y = y;
                                        if(x == 0) {
                                                active_flag = TRUE;
                                        } else if(!grid[x-1][y].active && grid[x-1][y].color) {
                                                active_flag = TRUE;
                                        }
                                }
                        }
                }
                if(!active_flag) {
                        for(int j = 0; j < 4; j++) {
                                shift_block(0, coord[j].x, coord[j].y);
                        }
                }
        }
}

static void shift_block(int right, int x, int y) {
        if(right) {
                grid[x + 1][y] = grid[x][y];
                grid[x][y].color = 0;
                grid[x][y].active = FALSE;
        } else {
                grid[x - 1][y] = grid[x][y];
                grid[x][y].color = 0;
                grid[x][y].active = 0;
        }
}

#endif
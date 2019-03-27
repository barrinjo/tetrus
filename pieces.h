#ifndef PIECES_H
#define PIECES_H

#include <time.h>

#include "global.h"

static void line_piece() {
        for(int i = 0; i < 4; i++) {
                grid[4][i].color = 1;
                grid[4][i].active = TRUE;
        }
}

static void j_piece() {
        for(int i = 0; i < 3; i++) {
                grid[4][i].color = 2;
                grid[4][i].active = TRUE;
        }
        grid[5][0].color = 2;
        grid[5][0].active = TRUE;
}

static void l_piece() {
        for(int i = 0; i < 3; i++) {
                grid[5][i].color = 3;
                grid[5][i].active = TRUE;
        }
        grid[4][0].color = 3;
        grid[4][0].active = TRUE;
}

static void square_piece() {
        for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                        grid[i + 4][j].color = 4;
                        grid[i + 4][j].active = TRUE;
                }
        }
}

static void s_piece() {
        grid[5][0].color = 5;
        grid[6][0].color = 5;
        grid[4][1].color = 5;
        grid[5][1].color = 5;
        grid[5][0].active = TRUE;
        grid[6][0].active = TRUE;
        grid[4][1].active = TRUE;
        grid[5][1].active = TRUE;
}

static void z_piece() {
        grid[4][0].color = 6;
        grid[5][0].color = 6;
        grid[5][1].color = 6;
        grid[6][1].color = 6;
        grid[4][0].active = TRUE;
        grid[5][0].active = TRUE;
        grid[5][1].active = TRUE;
        grid[6][1].active = TRUE;
}

static void t_piece() {
        for(int i = 0; i < 2; i++) {
                grid[3 + i][1].color = 7;
                grid[3 + i][1].active = TRUE;
        }
        grid[4][0].color = 7;
        grid[4][0].active = TRUE;
}

static void spawn_random_piece(void) {
        switch(rand()%6 + 1) {
                case 1 :
                        line_piece();
                        break;
                case 2 :
                        j_piece();
                        break;
                case 3 :
                        l_piece();
                        break;
                case 4 :
                        square_piece();
                        break;
                case 5 :
                        s_piece();
                        break;
                case 6 :
                        z_piece();
                        break;
                case 7 :
                        t_piece();
        }
}

#endif
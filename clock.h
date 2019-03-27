#ifndef CONTROLS_H
#define CONTROLS_H

#include "global.h"

static void lower_active_blocks(void);
static void move_block(int x, int y);
static gboolean no_active_blocks(void);
static void line_clear_check(void);
static void clear_lines(int y);

gboolean clock_tick(GtkWidget *widget) {
        if(no_active_blocks()) {
                line_clear_check();
                spawn_random_piece();
        }
        lower_active_blocks();

        gtk_widget_queue_draw(widget);
        return TRUE;
}

static void lower_active_blocks(void) {
        struct coord coord[4];
        gboolean active_flag = FALSE;
        int i = 0;
        for(int x = 0; x < 10; x++) {
                for(int y = 19; y >= 0; y--) {
                        if(grid[x][y].active == TRUE) {
                                coord[i].x = x;
                                coord[i++].y = y;
                                if(!grid[x][y+1].active && grid[x][y+1].color) {
                                        active_flag = TRUE;
                                }
                                if(y == 19)
                                        active_flag = TRUE;
                        }
                }
        }
        if(active_flag) {
                for(int j = 0; j < 4; j++) {
                        grid[coord[j].x][coord[j].y].active = FALSE;
                }
        } else  {
                for(int j = 0; j < 4; j++) {
                        move_block(coord[j].x, coord[j].y);
                }
        }
}

static gboolean no_active_blocks(void) {
        int active_flag = FALSE;
        for(int y = 0; y < 20; y++) {
                for(int x = 0; x < 10; x++) {
                        if(grid[x][y].active)
                                active_flag = TRUE;
                }
        }
        if(!active_flag)
                return TRUE;
        else
                return FALSE;
}

static void move_block(int x, int y) {
        if(y != 19 && !grid[x][y + 1].color) {
                grid[x][y + 1].color = grid[x][y].color;
                grid[x][y + 1].active = grid[x][y].active;
                grid[x][y].color = 0;
                grid[x][y].active = FALSE;
        } else {
                grid[x][y].active = FALSE;
        }
}

static void line_clear_check(void) {
        // printf("check\n");
        for(int y = 19; y >= 0; y--) {
                gboolean active_flag = FALSE;
                for(int x = 0; x < 10; x++) {
                        if(!grid[x][y].color)
                                active_flag = TRUE;
                }
                if(!active_flag) {
                        // printf("check2\n");
                        clear_lines(y++);
                }
        }
}

static void clear_lines(int y) {
        // printf("check1\n");
        for(y; y > 0; y--) {
                for(int x = 0; x < 10; x++) {
                        grid[x][y] = grid[x][y-1];
                }
        }
        for(int x = 0; x < 10; x++) {
                grid[x][0].color = 0;
                grid[x][0].active = FALSE;
                // printf("check3\n");
        }
}

#endif
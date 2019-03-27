#ifndef CONTROLS_H
#define CONTROLS_H

#include "global.h"

static void lower_active_blocks(void);
static void move_block(int x, int y);
static gboolean check_for_active_blocks(void);

gboolean clock_tick(GtkWidget *widget) {
        printf("tick\n");
        if(check_for_active_blocks()) {
                spawn_random_piece();
        }
        lower_active_blocks();

        gtk_widget_queue_draw(widget);
        return TRUE;
}

static void lower_active_blocks(void) {
        for(int x = 0; x < 10; x++) {
                int y;
                gboolean active_flag = FALSE;
                for(y = 19; y >= 0; y--) {
                        if(grid[x][y].active)
                                // active_flag = TRUE;
                                move_block(x, y);
                }
                // if(active_flag)
                //         move_block(x, y);
        }
}

static gboolean check_for_active_blocks(void) {
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

#endif
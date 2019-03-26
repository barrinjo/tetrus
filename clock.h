#ifndef CONTROLS_H
#define CONTROLS_H

static void lower_active_blocks(void);
static void move_block(int x, int y);

gboolean clock_tick(GtkWidget *widget) {
        lower_active_blocks();

        gtk_widget_queue_draw(widget);
        return TRUE;
}

static void lower_active_blocks(void) {
        for(int x = 0; x < 10; x++) {
                int y;
                gboolean active_flag = FALSE;
                for(y = 0; y < 20; y++) {
                        if(grid[x][y].active)
                                active_flag = TRUE;
                }
                if(active_flag)
                        move_block(x, y);
        }
}

static void move_block(int x, int y) {
        grid[x][y + 1].color = grid[x][y].color;
        grid[x][y + 1].active = grid[x][y].active;
        grid[x][y].color = 0;
        grid[x][y].active = FALSE;
        if(y)
                move_block(x, y-1);
}

#endif
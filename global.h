#ifndef GLOBAL_H
#define GLOBAL_H

struct block {
        int color;
        gboolean active;
};

struct coord {
        int x;
        int y;
};

// struct coord active_piece[4];
struct block grid[10][20];


#endif
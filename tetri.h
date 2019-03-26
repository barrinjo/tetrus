#ifndef TETRI_H
#define TETRI_H

#include "func.h"

int grid[10][20];

static void draw_grid(cairo_t *cr) {
        int color = 0;
        for(int y = 0; y < 20; y++) {
                for(int x = 0; x < 10; x++) {
                        grid[x][y] = color;
                        color++;
                        if(color == 8)
                                color = 0;
                }
        }
        cairo_set_line_join(cr, CAIRO_LINE_JOIN_ROUND);
        cairo_set_line_width(cr, 0);

        for(int x = 0; x < 10; x++) {
                for(int y = 0; y < 20; y++) {
                        switch(grid[x][y]) {
                                case 0 :
                                        // empty
                                        cairo_set_source_rgb(cr, rgb(96), rgb(98), rgb(102));
                                        break;
                                case 1 :
                                        // line piece
                                        cairo_set_source_rgb(cr, rgb(47), rgb(197), rgb(216));
                                        break;
                                case 2 :
                                        // J piece
                                        cairo_set_source_rgb(cr, rgb(20), rgb(35), rgb(204));
                                        break;
                                case 3 :
                                        // L piece
                                        cairo_set_source_rgb(cr, rgb(224), rgb(142), rgb(26));
                                        break;
                                case 4 :
                                        // square piece
                                        cairo_set_source_rgb(cr, rgb(252), rgb(240), rgb(5));
                                        break;
                                case 5 :
                                        // S piece
                                        cairo_set_source_rgb(cr, rgb(13), rgb(226), rgb(17));
                                        break;
                                case 6 :
                                        // Z piece
                                        cairo_set_source_rgb(cr, rgb(226), rgb(13), rgb(31));
                                        break;
                                case 7 :
                                        // T piece
                                        cairo_set_source_rgb(cr, rgb(226), rgb(13), rgb(191));
                        }


                        cairo_rectangle(cr, x*20 + 50, y*20 + 20, 20, 20);
                        cairo_stroke_preserve(cr);
                        cairo_fill(cr);
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
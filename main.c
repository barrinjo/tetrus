// if libffi breaks, use 'brew info libffi'
// and copy the export path for PKG_CONFIG

#include <cairo.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <math.h>

#include "grid.h"
#include "func.h"
#include "clock.h"

static void do_drawing(cairo_t *);

// connects the gtk event widget to the draw function in cairo
static gboolean on_draw_event(GtkWidget *widget,
			      cairo_t   *cr,
			      gpointer   user_data) {
	// do_drawing(cr);
	// clock_tick();
	draw_grid(cr);

	return FALSE;
}

static void do_drawing(cairo_t *cr) {
	// // sets source to pink
	// cairo_set_source_rgb(cr, rgb(47), rgb(130), rgb(28));
	// cairo_set_line_join(cr, CAIRO_LINE_JOIN_ROUND);
	// cairo_set_line_width(cr, 5);

	// //for each clicked coordinate in glob.coord, draws a rectangle at that point
	// for(int i = 0; i <= glob.count - 1; i++) {
	// 	// cairo_move_to(cr, glob.coordx[i]-15, glob.coordy[i]-15);
	// 	cairo_rectangle(cr, glob.coordx[i]-15, glob.coordy[i]-15, 30, 30);
	// }

	// cairo_stroke(cr);
}

static void key_press(GtkWidget   *widget,
		      GdkEventKey *event,
		      gpointer     user_data) {
	if(event->keyval == GDK_KEY_space) {
		printf("space key pressed\n");
		gtk_widget_queue_draw(widget);
	}
	if(event->keyval == GDK_KEY_Left) {
		printf("left key pressed\n");
	}
	if(event->keyval == GDK_KEY_Up) {
		printf("up key pressed\n");
	}
	if(event->keyval == GDK_KEY_Right) {
		printf("right key pressed\n");
	}
	if(event->keyval == GDK_KEY_Down) {
		printf("down key pressed\n");
	}
}

int main(int argc, char const *argv[])
{
	GtkWidget *window;
	GtkWidget *darea;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	darea = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), darea);
	gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);

	g_signal_connect(G_OBJECT(darea), "draw",
			 G_CALLBACK(on_draw_event), NULL);
	g_signal_connect(window, "destroy",
			 G_CALLBACK(gtk_main_quit), NULL);

	// g_signal_connect(window, "button-press-event",
	// 		 G_CALLBACK(button_press), NULL);
	// g_signal_connect(window, "button-release-event",
	// 		 G_CALLBACK(button_release), NULL);
	// g_signal_connect(window, "motion-notify-event",
	// 		 G_CALLBACK(mouse_motion), NULL);
	g_signal_connect(window, "key-press-event",
			 G_CALLBACK(key_press), NULL);

	g_timeout_add(1000, clock_tick, darea);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
	gtk_window_set_title(GTK_WINDOW(window), "tetrahedris");

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
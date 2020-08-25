#include "point.h"
#include <time.h>
#include <math.h>

point_screen screen;
point_canvas canvas;

int main(void) {
  srand(time(0));
  screen = new_point_screen(1280, 720, "Hello world!", false);
  canvas = new_point_canvas(0, 0, 1280, 720, 640, 360);
  point_screen_attach(screen, canvas);
  point_screen_start(screen);
  srand(time(0));
  while (point_screen_running(screen)) {
    for (int i = 0; i < 640; i++) {
      for (int j = 0; j < 360; j++) {
        point_canvas_plot(canvas, i, j, point_color_rgb(rand() % 255, rand() % 255, rand() % 255));
      }
    }
    point_screen_render(screen);
  }
  point_screen_deattach(screen, canvas);
  destroy_point_screen(screen);
  destroy_point_canvas(canvas);
  return 0;
}
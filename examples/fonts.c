#include "../point.h"

point_screen screen;
point_label label;
point_font font;

int main(void) {
  screen = new_point_screen(1280, 720, "point engine example 2: fonts and labels", false);
  font = new_point_font(point_image_load("resources/font.png"), 4, 6, 32, false);
  label = new_point_label(4, 4, "Hello world!", font, 4);
  point_screen_attach(screen, label);
  point_screen_start(screen);
  while (point_screen_running(screen)) point_screen_render(screen);
  point_screen_deattach(screen, label);
  destroy_point_screen(screen);
  destroy_point_label(label);
  destroy_point_font(font);
  return 0;
}
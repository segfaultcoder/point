#include "../point.h"

point_screen screen;
point_image image;
point_image_view imageview;

int main(void) {
  screen = new_point_screen(1280, 720, "point engine example 3: loading and showing images", false);
  image = point_image_load("resources/point.png");
  imageview = new_point_image_view(image, 440, 310, 400, 100);
  point_screen_attach(screen, imageview);
  point_screen_start(screen);
  while (point_screen_running(screen)) point_screen_render(screen);
  point_screen_deattach(screen, imageview);
  destroy_point_screen(screen);
  destroy_point_image_view(imageview);
  destroy_point_image(image);
  return 0;
}
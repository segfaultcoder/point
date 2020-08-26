#include "../point.h"
#include <time.h>
#include <math.h>

point_screen screen;
point_image image;
point_image_view imageviews[4000];

int main(void) {
  screen = new_point_screen(1280, 720, "point engine example 4: drawing images with tint and transparency", false);
  image = point_image_load("resources/point.png");
  for (int i = 0; i < 4000; i++) imageviews[i] = new_point_image_view(image, rand() % (screen->width - 160), rand() % (screen->height - 40), 160, 40);
  for (int i = 0; i < 4000; i++) point_screen_attach(screen, imageviews[i]);
  point_screen_start(screen);
  while (point_screen_running(screen)) {
    for (int i = 0; i < 4000; i++) {
      imageviews[i]->x = rand() % (screen->width - 160);
      imageviews[i]->y = rand() % (screen->height - 40);
      imageviews[i]->tint = point_color_rgba(rand() % 255, rand() % 255, rand() % 255, rand() % 255);
    }
    point_screen_render(screen);
  }
  for (int i = 0; i < 4000; i++) point_screen_deattach(screen, imageviews[i]);
  destroy_point_screen(screen);
  for (int i = 0; i < 4000; i++) destroy_point_image_view(imageviews[i]);
  destroy_point_image(image);
  return 0;
}
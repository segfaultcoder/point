# point
point is an easy to use, 2D/3D, GPU-accelerated engine based on SFML.



## Why C?

I chose C because it is the language I'm most used to, and also because it is faster than other languages like C#, Java, etc.



## How do I build a program with it?

That's easy! You only need to install libcsfml-dev, copy the library to your proyect and run this command on your terminal:

` $ gcc -lcsfml-graphics -lcsfml-window -lcsfml-system main.c -o main `



## Example

This example makes a 1280x720 window with a 640x360 canvas, connects them and draws random white pixels on the canvas. To see more details about how to use it, see the [wiki](google.com).

```c
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
    point_canvas_plot(canvas, rand() % 640, rand() % 360, point_color_rgb(255, 255, 255));
    point_screen_render(screen);
  }
  point_screen_deattach(screen, canvas);
  destroy_point_screen(screen);
  destroy_point_canvas(canvas);
  return 0;
}
```

/*
 * point engine: An easy to use, 2D/3D, GPU-accelerated engine based on SFML.
 * Made by segfaultcoder.
 * 
 * point/canvas.h
*/

#ifndef __POINT_CANVAS
#define __POINT_CANVAS

typedef point_object point_canvas;

// DECLARATION

point_canvas new_point_canvas(unsigned int x, unsigned int y, unsigned int viewwidth, unsigned int viewheight, unsigned int realwidth, unsigned int realheight);
void destroy_point_canvas(point_canvas canvas);

void point_canvas_plot(point_canvas canvas, unsigned int x, unsigned int y, point_color c);

void _point_canvas_render(point_object_args data) {
  point_object this = data->this;
  point_image image = this->data;
  sfSprite *sprite = sfSprite_create();
  sfVector2f pos = {this->x, this->y};
  sfVector2f scale = {this->width / image->width, this->height / image->height};
  sfSprite_setTexture(sprite, image->texture, true);
  sfSprite_setPosition(sprite, pos);
  sfSprite_setScale(sprite, scale);
  sfRenderWindow_drawSprite(data->window, sprite, NULL);
  sfSprite_destroy(sprite);
}

// IMPLEMENTATION

point_canvas new_point_canvas(unsigned int x, unsigned int y, unsigned int viewwidth, unsigned int viewheight, unsigned int realwidth, unsigned int realheight) {
  point_canvas canvas = new_point_object(x, y, viewwidth, viewheight);
  canvas->data = new_point_image(realwidth, realheight);
  canvas->render = &_point_canvas_render;
  return canvas;
}

void destroy_point_canvas(point_canvas canvas) {
  destroy_point_image(canvas->data);
  destroy_point_object(canvas);
}

void point_canvas_plot(point_canvas canvas, unsigned int x, unsigned int y, point_color c) {
  point_image_plot(canvas->data, x, y, c);
  point_image_update(canvas->data);
}

#endif
/*
 * point engine: An easy to use, 2D/3D, GPU-accelerated engine based on SFML.
 * Made by segfaultcoder.
 * 
 * point/object.h
*/

#ifndef __POINT_OBJECT
#define __POINT_OBJECT

typedef struct point_object {
  unsigned int x, y, width, height, maskx, masky, maskwidth, maskheight, count, id;
  point_color tint;
  struct point_object *next;
  void *data;
  void (*render)(void *);
} * point_object;

typedef struct point_object_args {
  point_object this;
  sfRenderWindow *window;
} * point_object_args;

// DECLARATION

point_object new_point_object(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
void destroy_point_object(point_object object);

// IMPLEMENTATION

point_object new_point_object(unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
  point_object object = malloc(sizeof(struct point_object));
  object->x = x;
  object->y = y;
  object->width = width;
  object->height = height;
  object->maskx = 0;
  object->masky = 0;
  object->maskwidth = width;
  object->maskheight = height;
  object->count = 0;
  object->id = -1;
  object->tint = point_color_white;
  object->next = NULL;
  object->data = NULL;
  object->render = NULL;
  return object;
}

void destroy_point_object(point_object object) {
  free(object);
}

#endif
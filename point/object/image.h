/*
 * point engine: An easy to use, 2D/3D, GPU-accelerated engine based on SFML.
 * Made by segfaultcoder.
 * 
 * point/object/image.h
*/

#ifndef __POINT_IMAGE_VIEW
#define __POINT_IMAGE_VIEW

typedef point_object point_image_view;

// DECLARATION

point_image_view new_point_image_view(point_image image, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
void destroy_point_image_view(point_image_view imageview);

void _point_image_view_render(void *dataptr);

// IMPLEMENTATION

point_image_view new_point_image_view(point_image image, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
  point_image_view imageview = new_point_object(x, y, width, height);
  imageview->data = image;
  imageview->render = &_point_image_view_render;
  return imageview;
}

void destroy_point_image_view(point_image_view imageview) {
  free(imageview);
}

void _point_image_view_render(void *dataptr) {
  point_object_args data = dataptr;
  point_object this = data->this;
  point_image image = this->data;
  sfSprite *sprite = sfSprite_create();
  sfVector2f pos = {this->x, this->y};
  sfVector2f scale = {this->width / image->width, this->height / image->height};
  sfSprite_setTexture(sprite, image->texture, true);
  sfSprite_setPosition(sprite, pos);
  sfSprite_setScale(sprite, scale);
  sfSprite_setColor(sprite, sfColor_fromInteger(this->tint));
  sfRenderWindow_drawSprite(data->window, sprite, NULL);
  sfSprite_destroy(sprite);
}

#endif
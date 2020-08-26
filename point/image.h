/*
 * point engine: An easy to use, 2D/3D, GPU-accelerated engine based on SFML.
 * Made by segfaultcoder.
 * 
 * point/image.h
*/

#ifndef __POINT_IMAGE
#define __POINT_IMAGE

typedef struct point_image {
  sfTexture *texture;
  unsigned int width;
  unsigned int height;
  unsigned char *pixels;
} * point_image;

// DECLARATION

point_image new_point_image(unsigned int width, unsigned int height);
void destroy_point_image(point_image image);

void point_image_update(point_image image);
void point_image_plot(point_image image, unsigned int x, unsigned int y, point_color c);

point_image point_image_load(char *path);

// IMPLEMENTATION

point_image new_point_image(unsigned int width, unsigned int height) {
  point_image image = malloc(sizeof(struct point_image));
  image->width = width;
  image->height = height;
  image->pixels = malloc(image->width * image->height * 4);
  image->texture = sfTexture_create(width, height);
  sfTexture_setRepeated(image->texture, false);
  sfTexture_setSmooth(image->texture, false);
  return image;
}

void destroy_point_image(point_image image) {
  sfTexture_destroy(image->texture);
  free(image);
}

void point_image_update(point_image image) {
  sfTexture_updateFromPixels(image->texture, image->pixels, image->width, image->height, 0, 0);
}

void point_image_plot(point_image image, unsigned int x, unsigned int y, point_color c) {
  image->pixels[0 + 4 * (x + (y * image->width))] = (unsigned char)(c >> 24);
  image->pixels[1 + 4 * (x + (y * image->width))] = (unsigned char)(c >> 16);
  image->pixels[2 + 4 * (x + (y * image->width))] = (unsigned char)(c >> 8);
  image->pixels[3 + 4 * (x + (y * image->width))] = (unsigned char)(c >> 0);
}

point_image point_image_load(char *path) {
  sfTexture *texture = sfTexture_createFromFile(path, NULL);
  point_image image = malloc(sizeof(struct point_image));
  image->width = sfTexture_getSize(texture).x;
  image->height = sfTexture_getSize(texture).y;
  image->pixels = malloc(image->width * image->height * 4);
  image->texture = texture;
  sfTexture_setRepeated(image->texture, false);
  sfTexture_setSmooth(image->texture, false);
  point_image_update(image);
  return image;
}

#endif
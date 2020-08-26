/*
 * point engine: An easy to use, 2D/3D, GPU-accelerated engine based on SFML.
 * Made by segfaultcoder.
 * 
 * point/font.h
*/

#ifndef __POINT_FONT
#define __POINT_FONT

typedef struct point_font {
  unsigned int charwidth, charheight, charsperrow;
  bool fullascii;
  point_image image;
} * point_font;

// DECLARATION

point_font new_point_font(point_image image, unsigned int charwidth, unsigned int charheight, unsigned int charsperrow, bool fullascii);
void destroy_point_font(point_font font);

// IMPLEMENTATION

point_font new_point_font(point_image image, unsigned int charwidth, unsigned int charheight, unsigned int charsperrow, bool fullascii) {
  point_font font = malloc(sizeof(struct point_font));
  font->image = image;
  font->charwidth = charwidth;
  font->charheight = charheight;
  font->charsperrow = charsperrow;
  font->fullascii = fullascii;
  return font;
}

void destroy_point_font(point_font font) {
  free(font);
}

#endif
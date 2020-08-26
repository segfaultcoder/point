/*
 * point engine: An easy to use, 2D/3D, GPU-accelerated engine based on SFML.
 * Made by segfaultcoder.
 * 
 * point/object/label.h
*/

#ifndef __POINT_LABEL
#define __POINT_LABEL

typedef point_object point_label;

typedef struct point_label_data {
  char *text;
  point_font font;
  unsigned int size;
} * point_label_data;

// DECLARATION

point_label new_point_label(unsigned int x, unsigned int y, char *text, point_font font, unsigned int size);
void destroy_point_label(point_label label);

char *point_label_get_text(point_label label);
point_font point_label_get_font(point_label label);
unsigned int point_label_get_size(point_label label);

void point_label_set_text(point_label label, char *text);
void point_label_set_font(point_label label, point_font font);
void point_label_set_size(point_label label, unsigned int size);

void _point_label_render(void *dataptr);

// IMPLEMENTATION

point_label new_point_label(unsigned int x, unsigned int y, char *text, point_font font, unsigned int size) {
  point_label label = new_point_object(x, y, size * font->charwidth * strlen(text), font->charheight);
  label->data = malloc(sizeof(struct point_label_data));
  point_label_data data = label->data;
  data->text = text;
  data->font = font;
  data->size = size;
  label->render = &_point_label_render;
  return label;
}

void destroy_point_label(point_label label) {
  free(label->data);
  free(label);
}

char *point_label_get_text(point_label label) {
  point_label_data data = label->data;
  return data->text;
}

point_font point_label_get_font(point_label label) {
  point_label_data data = label->data;
  return data->font;
}

unsigned int point_label_get_size(point_label label) {
  point_label_data data = label->data;
  return data->size;
}

void point_label_set_text(point_label label, char *text) {
  point_label_data data = label->data;
  data->text = text;
  label->width = data->size * data->font->charwidth * strlen(data->text);
  label->maskwidth = data->size * data->font->charwidth * strlen(data->text);
  label->height = data->font->charheight;
  label->maskheight = data->font->charheight;
}

void point_label_set_font(point_label label, point_font font) {
  point_label_data data = label->data;
  data->font = font;
  label->width = data->size * data->font->charwidth * strlen(data->text);
  label->maskwidth = data->size * data->font->charwidth * strlen(data->text);
  label->height = data->font->charheight;
  label->maskheight = data->font->charheight;
}

void point_label_set_size(point_label label, unsigned int size) {
  point_label_data data = label->data;
  data->size = size;
  label->width = data->size * data->font->charwidth * strlen(data->text);
  label->maskwidth = data->size * data->font->charwidth * strlen(data->text);
  label->height = data->font->charheight;
  label->maskheight = data->font->charheight;
}

void _point_label_render(void *dataptr) {
  point_object_args args = dataptr;
  point_object this = args->this;
  point_label_data data = this->data;
  for (unsigned int i = 0; i < strlen(data->text); i++) {
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {this->x + (data->size * data->font->charwidth * i), this->y};
    sfVector2f scale = {data->size, data->size};
    sfSprite_setTexture(sprite, data->font->image->texture, true);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    unsigned int texx = ((unsigned int)(data->text[i]) % data->font->charsperrow) * data->font->charwidth;
    unsigned int texy = ((unsigned int)(data->text[i]) / data->font->charsperrow) * data->font->charheight;
    sfIntRect subsprite = {texx, texy, data->font->charwidth, data->font->charheight};
    sfSprite_setTextureRect(sprite, subsprite);
    sfRenderWindow_drawSprite(args->window, sprite, NULL);
    sfSprite_destroy(sprite);
  }
}

#endif
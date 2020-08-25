/*
 * point engine: An easy to use, 2D/3D, GPU-accelerated engine based on SFML.
 * Made by segfaultcoder.
 * 
 * point/screen.h
*/

#ifndef __POINT_SCREEN
#define __POINT_SCREEN

typedef struct point_screen {
  unsigned int width, height, count;
  unsigned long long ticks;
  char *title;
  bool fullscreen;
  bool running;
  point_object objects;
  sfRenderWindow *window;
} * point_screen;

// DECLARATION

point_screen new_point_screen(unsigned int width, unsigned int height, char *title, bool fullscreen);
void destroy_point_screen(point_screen screen);

void point_screen_attach(point_screen screen, point_object object);
void point_screen_deattach(point_screen screen, point_object object);

void point_screen_render(point_screen screen);

bool point_screen_running(point_screen screen);

void point_screen_start(point_screen screen);
void point_screen_stop(point_screen screen);

// IMPLEMENTATION

point_screen new_point_screen(unsigned int width, unsigned int height, char *title, bool fullscreen) {
  sfVideoMode mode = {width, height, 32};
  point_screen screen = malloc(sizeof(struct point_screen));
  screen->width = width;
  screen->height = height;
  screen->count = 0;
  screen->title = title;
  screen->fullscreen = false;
  screen->running = false;
  screen->objects = NULL;
  screen->ticks = 0;
  screen->window = sfRenderWindow_create(mode, screen->title, sfClose | (fullscreen * sfFullscreen), NULL);
  return screen;
}

void destroy_point_screen(point_screen screen) {
  sfRenderWindow_close(screen->window);
  sfRenderWindow_destroy(screen->window);
  free(screen);
}

void point_screen_attach(point_screen screen, point_object object) {
  if (screen->objects == NULL || screen->count <= 0) {
    screen->objects = object;
    object->next = NULL;
    object->id = screen->count;
    screen->count = 1;
  } else {
    point_object tmp = screen->objects;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = object;
    object->next = NULL;
    object->id = screen->count;
    screen->count++;
  }
}

void point_screen_deattach(point_screen screen, point_object object) {
  if (screen->objects == NULL || screen->count <= 0 || object == NULL) return;
  if (screen->objects->next == NULL || screen->objects->id == object->id) {
    screen->objects = screen->objects->next;
    point_object tmp = object->next;
    while (tmp != NULL) {
      tmp->id--;
      tmp = tmp->next;
    }
    object->next = NULL;
    object->id = -1;
    screen->count--;
  } else {
    point_object tmp = screen->objects;
    bool found = false;
    while (tmp->next != NULL || !found) {
      if (tmp->id == object->id) found = true;
      else tmp = tmp->next;
    }
    if (found) {
      tmp->next = tmp->next->next;
      point_object tmp2 = object->next;
      while (tmp2 != NULL) {
        tmp2->id--;
        tmp2 = tmp2->next;
      }
      object->next = NULL;
      object->id = -1;
      screen->count--;
    }
  }
}

void point_screen_render(point_screen screen) {
  if (point_screen_running(screen)) {
    sfRenderWindow_clear(screen->window, sfBlack);
    sfEvent event;
    if (sfRenderWindow_pollEvent(screen->window, &event)) {
      if (event.type == sfEvtClosed) point_screen_stop(screen);
    }
    point_object object = screen->objects;
    while (object != NULL) {
      point_object_args args = malloc(sizeof(struct point_object_args));
      args->this = object;
      args->window = screen->window;
      (*(object->render))(args);
      object = object->next;
    }
    sfRenderWindow_display(screen->window);
    screen->ticks++;
  }
}

bool point_screen_running(point_screen screen) {
  return screen->running;
}

void point_screen_start(point_screen screen) {
  screen->running = true;
}

void point_screen_stop(point_screen screen) {
  screen->running = false;
}

#endif
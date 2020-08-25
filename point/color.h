/*
 * point engine: An easy to use, 2D/3D, GPU-accelerated engine based on SFML.
 * Made by segfaultcoder.
 * 
 * point/color.h
*/

#ifndef __POINT_COLOR
#define __POINT_COLOR

typedef unsigned int point_color;

#define point_color_pink         point_color_rgb(255, 127, 127)
#define point_color_light_orange point_color_rgb(255, 191, 127)
#define point_color_light_yellow point_color_rgb(255, 255, 127)
#define point_color_light_lime   point_color_rgb(191, 255, 127)
#define point_color_light_green  point_color_rgb(127, 255, 127)
#define point_color_light_cyan   point_color_rgb(127, 255, 255)
#define point_color_light_blue   point_color_rgb(127, 127, 255)
#define point_color_light_purple point_color_rgb(255, 127, 255)
#define point_color_red          point_color_rgb(255, 0, 0)
#define point_color_orange       point_color_rgb(255, 127, 0)
#define point_color_yellow       point_color_rgb(255, 255, 0)
#define point_color_lime         point_color_rgb(127, 255, 0)
#define point_color_green        point_color_rgb(0, 255, 0)
#define point_color_cyan         point_color_rgb(0, 255, 255)
#define point_color_blue         point_color_rgb(0, 0, 255)
#define point_color_purple       point_color_rgb(255, 0, 255)
#define point_color_dark_red     point_color_rgb(127, 0, 0)
#define point_color_brown        point_color_rgb(127, 63, 0)
#define point_color_dark_yellow  point_color_rgb(127, 127, 0)
#define point_color_dark_lime    point_color_rgb(63, 127, 0)
#define point_color_dark_green   point_color_rgb(0, 127, 0)
#define point_color_dark_cyan    point_color_rgb(0, 127, 127)
#define point_color_dark_blue    point_color_rgb(0, 0, 127)
#define point_color_dark_purple  point_color_rgb(127, 0, 127)
#define point_color_white        point_color_rgb(255, 255, 255)
#define point_color_light_gray   point_color_rgb(191, 191, 191)
#define point_color_gray         point_color_rgb(127, 127, 127)
#define point_color_dark_gray    point_color_rgb(63, 63, 63)
#define point_color_black        point_color_rgb(0, 0, 0)

// DECLARATION

point_color point_color_rgb(unsigned char r, unsigned char g, unsigned char b);
point_color point_color_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

// IMPLEMENTATION

point_color point_color_rgb(unsigned char r, unsigned char g, unsigned char b) {
  return point_color_rgba(r, g, b, 255);
}

point_color point_color_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
  return ((unsigned int)(r) << 24) | ((unsigned int)(g) << 16) | ((unsigned int)(b) << 8) | (unsigned int)(a);
}

#endif
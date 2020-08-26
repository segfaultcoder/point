/*
 * point engine: An easy to use, 2D/3D, GPU-accelerated engine based on SFML.
 * Made by segfaultcoder.
 * 
 * Last updated on: 08/26/2020
 * 
 * List of platforms(X if implemented, - if in progress):
 *  - ( ) Windows
 *  - (-) Linux
 *  - ( ) MacOS X
 *  - ( ) Android
 *  - ( ) Nintendo Switch
 *  - ( ) PS Vita
*/

#ifndef __POINT
#define __POINT

#include <stdlib.h>

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef unsigned char bool;
#define true  1
#define false 0

#include "point/platform.h"

#include "point/object.h"
#include "point/screen.h"

#include "point/color.h"
#include "point/image.h"
#include "point/font.h"

#include "point/object/canvas.h"
#include "point/object/button.h"
#include "point/object/image.h"
#include "point/object/label.h"
#include "point/object/panel.h"
#include "point/object/sprite.h"
#include "point/object/textbox.h"
#include "point/object/view3d.h"

#endif
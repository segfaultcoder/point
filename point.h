/*
 * point engine: An easy to use, 2D/3D, GPU-accelerated engine based on SFML.
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
 * 
 * Copyright 2020 segfaultcoder
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#ifndef __POINT
#define __POINT

#include <stdlib.h>
#include <string.h>

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef unsigned char bool;
#define true  1
#define false 0

#include "point/platform.h"

#include "point/color.h"

#include "point/object.h"
#include "point/screen.h"

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
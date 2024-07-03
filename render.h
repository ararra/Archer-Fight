#pragma once

#include "common.h"


extern Game game;
extern Character gay;
 

void draw_all_layers(tmx_map* map, tmx_layer* layers);
void draw_objects(tmx_object_group *objgr);
void draw_image_layer(tmx_image *image);
void draw_layer(tmx_map* map, tmx_layer* layers);
void draw_tile(void *image, unsigned int sx, unsigned int sy, unsigned int sw, unsigned int sh,
               unsigned int dx, unsigned int dy, float opacity, unsigned int flags);
               

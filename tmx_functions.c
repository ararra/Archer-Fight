void draw_all_layers(tmx_map *map, tmx_layer *layers) {
  while (layers) {
    if (layers->visible) {

      if (layers->type == L_GROUP) {
        draw_all_layers(map, layers->content.group_head); // recursive call
      }
      else if (layers->type == L_OBJGR) {
        draw_objects(layers->content.objgr); // Function to be implemented
      }
      else if (layers->type == L_IMAGE) {
        draw_image_layer(layers->content.image); // Function to be implemented
      }
      else if (layers->type == L_LAYER) {
        draw_layer(map, layers); // Function to be implemented
      }
    }
    layers = layers->next;
  }
}

void draw_image_layer(tmx_image *image) {
  SDL_Rect dim;
  dim.x = dim.y = 0;

  SDL_Texture *texture = (SDL_Texture*)image->resource_image; // Texture loaded by libTMX
  SDL_QueryTexture(texture, NULL, NULL, &(dim.w), &(dim.h));
  SDL_RenderCopy(ren, texture, NULL, &dim);
}

void draw_layer(tmx_map *map, tmx_layer *layer) {
  unsigned long i, j;
  unsigned int gid, x, y, w, h, flags;
  float op;
  tmx_tileset *ts;
  tmx_image *im;
  void* image;
  op = layer->opacity;
  for (i=0; i<map->height; i++) {
    for (j=0; j<map->width; j++) {
      gid = (layer->content.gids[(i*map->width)+j]) & TMX_FLIP_BITS_REMOVAL;
      if (map->tiles[gid] != NULL) {
        ts = map->tiles[gid]->tileset;
        im = map->tiles[gid]->image;
        x  = map->tiles[gid]->ul_x;
        y  = map->tiles[gid]->ul_y;
        w  = ts->tile_width;
        h  = ts->tile_height;
        if (im) {
          image = im->resource_image;
        }
        else {
          image = ts->image->resource_image;
        }
        flags = (layer->content.gids[(i*map->width)+j]) & ~TMX_FLIP_BITS_REMOVAL;
        draw_tile(image, x, y, w, h, j*ts->tile_width, i*ts->tile_height, op, flags); // Function to be implemented
      }
    }
  }
}

void draw_tile(void *image, unsigned int sx, unsigned int sy, unsigned int sw, unsigned int sh,
               unsigned int dx, unsigned int dy, float opacity, unsigned int flags) {
  SDL_Rect src_rect, dest_rect;
  src_rect.x = sx;
  src_rect.y = sy;
  src_rect.w = dest_rect.w = sw;
  src_rect.h = dest_rect.h = sh;
  dest_rect.x = dx;
  dest_rect.y = dy;
  SDL_RenderCopy(ren, (SDL_Texture*)image, &src_rect, &dest_rect);
}


void draw_polyline(double **points, double x, double y, int pointsc) {
  int i;
  for (i=1; i<pointsc; i++) {
    SDL_RenderDrawLine(ren, x+points[i-1][0], y+points[i-1][1], x+points[i][0], y+points[i][1]);
  }
}

void draw_polygon(double **points, double x, double y, int pointsc) {
  draw_polyline(points, x, y, pointsc);
  if (pointsc > 2) {
    SDL_RenderDrawLine(ren, x+points[0][0], y+points[0][1], x+points[pointsc-1][0], y+points[pointsc-1][1]);
  }
}

void draw_objects(tmx_object_group *objgr) {
  SDL_Rect rect;
  set_color(objgr->color);
  tmx_object *head = objgr->head;
  while (head) {
    if (head->visible) {
      if (head->obj_type == OT_SQUARE) {
        rect.x =     head->x;  rect.y =      head->y;
        rect.w = head->width;  rect.h = head->height;
        SDL_RenderDrawRect(ren, &rect);
      }
      else if (head->obj_type  == OT_POLYGON) {
        draw_polygon(head->content.shape->points, head->x, head->y, head->content.shape->points_len);
      }
      else if (head->obj_type == OT_POLYLINE) {
        draw_polyline(head->content.shape->points, head->x, head->y, head->content.shape->points_len);
      }
      else if (head->obj_type == OT_ELLIPSE) {
        /* FIXME: no function in SDL2 */
      }
    }
    head = head->next;
  }
}
#pragma once

#include "common.h"
#define COLLIMIT 100



typedef struct Game{    
    bool quit;
    SDL_Renderer *renderer;
    SDL_Window *window;

    tmx_map* map;

    tmx_tileset *tileset;

    tmx_layer* mapCollisions;

    int camX;
    int camY;
}Game;


typedef struct Character{
    int x,y;
    int w,h;
    int sprite_x, sprite_y;

    float health, mana;
    
    int stats;

    SDL_Texture* currSprite;

    //sprite
    //inventory

}Character;


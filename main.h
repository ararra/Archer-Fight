#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tmx_functions.h"


typedef struct Game
{    

    bool quit;
    SDL_Renderer *renderer;
    SDL_Window *window;

    tmx_map* map;
    tmx_tileset *tileset;

    int camX;
    int camY;
    

}Game;

Game game;


typedef struct Character
{
    int x,y;
    float health, mana;
    
    int stats;

    SDL_Texture* sprite;

    //sprite
    //inventory

}Character;

Character gay ;


void loadMap();
void loadChar();

void initGame();
void inputHandler(SDL_Event *e);
void* SDL_tex_loader(const char *path);
void shutdown();
void render_map(tmx_map *map);
void renderChar();

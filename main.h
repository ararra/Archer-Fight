#pragma once
#include <stdbool.h>
#include <stdlib.h>


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "third_party/tmx-tmx_1.2.0/src/tmx.h"


typedef struct Game
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Texture * tileSet;
    tmx_tileset * tmxTileSet;
    tmx_map *map;
    
    tmx_resource_manager* tmxResMan;

    tmx_object **collisions;
    int *colTileIndex;
    int collisionCount;
    tmx_object *col;

}Game;



typedef struct Char
{
    SDL_Texture* mTexture[6];
    SDL_Rect spriteClip[25];

    double direction;
    int spriteState;

    double xPosition, yPosition;
    int width, height;

    int Health;
    int Mana;

    int Str;
    int Int;


}Char;

enum spriteState
{
    DOWN_IDLE = 0,
    DIAG_DOWN = 1,
    DIAG_UP = 5,
    UP_WALK = 9,
    RIGHT_WALK = 13,
    DOWN_WALK = 17,
    LEFT_WALK = 21
};

 


void init();
void run();
void shutdown();

//fileHandling
void loadGameFiles();
void loadChar();
void loadMap();

//Logic
bool intersectRectAndLine(SDL_FRect colBox, float x1, float y1, float x2, float y2);


//Event
void input(SDL_Event *e);
bool collisionCheck();

//Rendering
void draw();
void draw_all_layers();
void draw_objects();
void draw_image_layer();
void draw_layer();

void renderMap(tmx_layer* layer);
void renderChar();

void* SDL_tex_loader(const char *path);


//Misc
void getCollData();
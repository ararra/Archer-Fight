#include "init.h"

void initGame()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0 )
    {
        printf("failed to initialize SDL: %s ", SDL_GetError());
        exit(EXIT_FAILURE);    
    }
    if(IMG_Init(IMG_INIT_PNG) == 0 )
    {
        printf("failed to initialize SDL: %s ", SDL_GetError());
        exit(EXIT_FAILURE);    
    }
    
    
    game.window = SDL_CreateWindow("ArcherFight", SDL_WINDOWPOS_UNDEFINED ,SDL_WINDOWPOS_UNDEFINED , WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if(game.window == NULL)
    {
        printf("failed to create window %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(game.renderer == NULL)
    {
        printf("failed to create renderer %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

void loadMap(){
    game.map = tmx_load("assets/maps/testmap.tmx");
    
    game.mapCollisions = game.map->ly_head->next->next;
    
    if (game.map == NULL) {
        tmx_perror("Cannot load map");
        exit(EXIT_FAILURE);
    }   
}

void loadChar()
{   
    SDL_Surface* surfy = IMG_Load("assets/sprite/character.png");

    gay.h = 10;////these values need to be corrected.
    gay.w = 10;

    gay.currSprite = SDL_CreateTextureFromSurface(game.renderer, surfy);

    

}

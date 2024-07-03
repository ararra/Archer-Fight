#pragma once

#include "common.h"
#include "init.h"
#include "render.h"
#include "update.h"


void render_map(tmx_map *map);

void inputManager(SDL_Event *e);
void* SDL_tex_loader(const char *path);
void shutdown();
void renderChar();


//Update
void updateManager();


bool checkCollisionUp();
bool checkCollisionDown();
bool checkCollisionRight();
bool checkCollisionLeft();

void moveChar(int x, int y);

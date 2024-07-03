
#include "main.h"

Game game;
Character gay;

int main(void)
{
    tmx_img_load_func = SDL_tex_loader;
    tmx_img_free_func = (void (*)(void*))SDL_DestroyTexture;
    
    initGame();
    loadMap();
    loadChar();
    game.quit = false;



    SDL_Event e;

    while (!game.quit)
    { 
    
       //Input

        while (SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                game.quit = true;
            }
            if (e.type == SDL_KEYDOWN)
            {

              inputManager(&e);
              // PRINT HERE FOR MOVEMENT DEBUG... I THINK.
              printf("%d, %d \n", gay.x, gay.y);


            }
        }
             
        //Update
        collfunc();

        //Rendering
        SDL_RenderClear(game.renderer);

        render_map(game.map);
        renderChar();

        SDL_RenderPresent(game.renderer);

    }

    return 0;
}


void spriteDownSequence() {
  gay.sprite_x = MOVEX;
  gay.sprite_y = DOWNY;
}
void spriteUpSequence() {
  gay.sprite_x = MOVEX;
  gay.sprite_y = UPY;
}
void spriteLeftSequence() {
  gay.sprite_x = MOVEX;
  gay.sprite_y = LEFTY;
}
void spriteRightSequence() {
  gay.sprite_x = MOVEX;
  gay.sprite_y = RIGHTY;
}
void inputManager(SDL_Event *e) {

	switch (e->key.keysym.sym)
	{
	case SDLK_DOWN:
		if(!checkCollisionDown())
		{
    	moveChar(0, 10);
      spriteDownSequence();
    }
		break;  

	case SDLK_UP:
		if(!checkCollisionUp())
		{
      moveChar(0,-10);
      spriteUpSequence();
    }
		break;  

	case SDLK_LEFT:
		if(!checkCollisionLeft())
    {			
      moveChar(-10, 0);
      spriteLeftSequence();
    }
		break;  

  case SDLK_RIGHT:
		if(!checkCollisionRight())
    {
    	moveChar(10, 0);
      spriteRightSequence();
    }
    break;
  
	default:
		break;
  }
}


bool checkCollisionUp()
{
  return false;
}

bool checkCollisionDown()
{
  return false;
}

bool checkCollisionRight()
{
  return false;
}

bool checkCollisionLeft()
{
  return false;
}

void* SDL_tex_loader(const char *path) 
{
    return IMG_LoadTexture(game.renderer, path);
}

void moveChar(int x, int y)
{  

  gay.x += x;
  gay.y += y;


  //  follow the char
  // game.camX -= x;
  // game.camY -= y;

	return;
}

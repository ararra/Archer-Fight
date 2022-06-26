#include "main.h"


Game game = {};


const int gWidth = 1280;
const int gHeight = 960;
Char mainChar = {}; 
void* images[19 * 45]; //tilemap arr


int main()
{       
    tmx_img_load_func = SDL_tex_loader;
    tmx_img_free_func = (void (*)(void*))SDL_DestroyTexture;


    init();

    run();

    shutdown(); 
     
}

void init()
{


    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Failed to init SDL, %s ", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG) == 0)
    {
        printf("failed to init SDL_IMAGE, %s ", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    

    if(SDL_CreateWindowAndRenderer(gWidth, gHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &game.window, &game.renderer) != 0)
    {
        printf("failed to create window or renderer, %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }


    loadGameFiles();
    

}

void run()
{

    SDL_Event e;
    bool quitVar = false;

    while(!quitVar)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                quitVar = true;
            }
            if(e.type == SDL_KEYDOWN)
            {
                input(&e);
            }
            else if(e.type == SDL_KEYUP) //put animation state in idle pos when done walking etc.
            {
                mainChar.spriteState = DOWN_IDLE;
            }
        }

        draw();

    }
}

void shutdown()
{

}

//textures and whatever
void loadGameFiles()       
{

    loadChar();

    loadMap();


    mainChar.xPosition = 22;
    mainChar.yPosition = 22;

}

void* SDL_tex_loader(const char *path) {
    return IMG_LoadTexture(game.renderer, path);
}

void loadMap()
{

    game.tileSet = IMG_LoadTexture(game.renderer, "assets/Serene_Village_32x32.png");

    game.map = tmx_load("assets/second.tmx");
    if(game.map == NULL)
    {
        printf("map not loaded: %d: %s\n", tmx_errno, tmx_strerr());
        exit(EXIT_FAILURE);
    }

    getCollData();

}

void getCollData()
{
    game.collisionCount = 0; //reset for every map here or somewhere else, need to empty and realloc pointer array

    if(game.map->ts_head == NULL) 
    {
        printf("tileset not loaded");
        exit(EXIT_FAILURE);
    }


    printf("game col count %d\n",game.map->tilecount );

    game.colTileIndex = malloc((game.map->tilecount) * sizeof(int*));

    int collsAdded = 0;
    for(int i = 1; i< game.map->tilecount; i++) //count all tiles with collision
    {
        if(game.map->tiles[i]->collision != NULL)
        {
            game.colTileIndex[game.collisionCount] = i;
            game.collisionCount++;
        }
    }
    game.colTileIndex = realloc(game.colTileIndex, (game.collisionCount) * sizeof(int*));

}

void loadChar()
{
    //idle down
    mainChar.mTexture[0] = IMG_LoadTexture(game.renderer, "using/2.png");

    int w, h;
    SDL_QueryTexture(mainChar.mTexture[0], NULL, NULL,&w, &h);
    mainChar.width = w;
    mainChar.height = h;

    mainChar.spriteClip[0].h = h;
    mainChar.spriteClip[0].w = w;
    mainChar.spriteClip[0].x = 0;
    mainChar.spriteClip[0].y = 0;
    //

    SDL_Surface* surface = IMG_Load("using/2_diagdown.png");
    SDL_Surface* surface1 = IMG_Load("using/2_diagup.png");
    SDL_Surface* surface2 = IMG_Load("using/2_north.png");
    SDL_Surface* surface3 = IMG_Load("using/2_side.png");
    SDL_Surface* surface4 = IMG_Load("using/2_south2.png");

    mainChar.mTexture[1] = SDL_CreateTextureFromSurface(game.renderer, surface);
    mainChar.mTexture[2] = SDL_CreateTextureFromSurface(game.renderer, surface1);
    mainChar.mTexture[3] = SDL_CreateTextureFromSurface(game.renderer, surface2);
    mainChar.mTexture[4] = SDL_CreateTextureFromSurface(game.renderer, surface3);
    mainChar.mTexture[5] = SDL_CreateTextureFromSurface(game.renderer, surface4);

    for(int i = 0; i < 4; i++)
    {
        //diag down
        mainChar.spriteClip[i+1].h = surface->h;
        mainChar.spriteClip[i+1].w = surface->w/4;
        mainChar.spriteClip[i+1].x = i*surface->w/4;
        mainChar.spriteClip[i+1].y = 0;
        //diagup
        mainChar.spriteClip[i+5].h = surface1->h;
        mainChar.spriteClip[i+5].w = surface1->w/4;
        mainChar.spriteClip[i+5].x = i*surface1->w/4;
        mainChar.spriteClip[i+5].y = 0;
        //north
        mainChar.spriteClip[i+9].h = surface2->h;
        mainChar.spriteClip[i+9].w = surface2->w/4;
        mainChar.spriteClip[i+9].x = i*surface2->w/4;
        mainChar.spriteClip[i+9].y = 0;
        //side left
        mainChar.spriteClip[i+13].h = surface3->h;
        mainChar.spriteClip[i+13].w = surface3->w/4;
        mainChar.spriteClip[i+13].x = i*surface3->w/4;
        mainChar.spriteClip[i+13].y = 0;
        //south
        mainChar.spriteClip[i+17].h = surface4->h;
        mainChar.spriteClip[i+17].w = surface4->w/4;
        mainChar.spriteClip[i+17].x = i*surface4->w/4;
        mainChar.spriteClip[i+17].y = 0;
        //side right
        mainChar.spriteClip[i+21].h = surface3->h;
        mainChar.spriteClip[i+21].w = surface3->w/4;
        mainChar.spriteClip[i+21].x = i*surface3->w/4;
        mainChar.spriteClip[i+21].y = 0;
    }
    
}


void input(SDL_Event* e)
{
    //Movement
    if(e->type == SDL_KEYUP)
    {
        mainChar.spriteState = DOWN_IDLE;
    }
    if((e->key.keysym.sym == SDLK_UP) && !collisionCheck())
    {
        
        if(mainChar.spriteState >= UP_WALK && mainChar.spriteState <= UP_WALK + 2)
        {
            mainChar.spriteState++;
        }
        else{mainChar.spriteState = UP_WALK;}

        mainChar.yPosition -= 8;
    }
    if(e->key.keysym.sym == SDLK_LEFT && !collisionCheck())
    {
        if(mainChar.spriteState >= LEFT_WALK && mainChar.spriteState <= LEFT_WALK + 2)
        {
            mainChar.spriteState++;
        }
        else{mainChar.spriteState = LEFT_WALK;}

        mainChar.xPosition -= 8;
    }
    if(e->key.keysym.sym == SDLK_RIGHT && !collisionCheck())
    {
        if(mainChar.spriteState >= RIGHT_WALK && mainChar.spriteState <= RIGHT_WALK + 2)
        {
            mainChar.spriteState++;
        }
        else{mainChar.spriteState = RIGHT_WALK;}
        mainChar.xPosition += 8;
    }
    if(e->key.keysym.sym == SDLK_DOWN && !collisionCheck())
    {
        if(mainChar.spriteState >= DOWN_WALK && mainChar.spriteState <= DOWN_WALK + 2)
        {
            mainChar.spriteState++;
        }
        else{mainChar.spriteState = DOWN_WALK;}

        mainChar.yPosition += 8;
    }
    if(e->key.keysym.sym == SDLK_z)
    {
        //attack
    }
    if(e->key.keysym.sym == SDLK_x)
    {
        //interact
    }
    

}
bool collisionCheck()
{
    bool colCheck = false;

    for(int i = 0; i < game.collisionCount; i++)
    {    
        tmx_object* collisions = game.map->tiles[game.colTileIndex[i]]->collision;
        int colss = game.colTileIndex[i] & TMX_FLIP_BITS_REMOVAL;

        int xx = (colss % game.map->width);
        int yy = (colss - xx) /game.map->width;

        int x = xx *game.map->tile_width;
        int y = yy *game.map->tile_height;

        //square col box
        printf("col obj typ %d \n", collisions->obj_type);
        if(collisions->obj_type == 1) 
        {
            SDL_Rect charColBox; 
            charColBox.x = mainChar.xPosition;
            charColBox.y = mainChar.yPosition;
            charColBox.w = mainChar.width + 1;
            charColBox.h = mainChar.height + 1;


            SDL_Rect objCollBox;
            objCollBox.h = collisions->height;
            objCollBox.w = collisions->width;
            objCollBox.x = collisions->x;
            objCollBox.y = collisions->y;

            colCheck = SDL_HasIntersection(&charColBox, &objCollBox); 
        }              

        //polygon col box
        if(collisions->obj_type == 2)
        {
            for(int j = 1; j < collisions->content.shape->points_len; j++)
            {
                SDL_Rect charColBox; 
                charColBox.x = mainChar.xPosition;
                charColBox.y = mainChar.yPosition;
                charColBox.w = mainChar.width*2;
                charColBox.h = mainChar.height*2;
                
                int x1 = (int)(x + collisions->content.shape->points[j-1][0]);                  //last line not considered
                int y1 = (int)(y + collisions->content.shape->points[j-1][1]);
                int x2 = (int)(x + collisions->content.shape->points[j][0]);
                int y2 = (int)(y + collisions->content.shape->points[j][1]);


                printf("colbox int: (x1,y1):(%d,%d)  (x2,y2):(%d,%d)\n", x1, y1, x2, y2);

                colCheck = SDL_IntersectRectAndLine(&charColBox, &x1, &y1, &x2, &y2 );
            }
        }        

        printf("colcount %d \n", i);
    }
    printf("char pos %f, %f  \n", mainChar.xPosition, mainChar.yPosition );


    return colCheck;
}

bool intersectRectAndLine(SDL_FRect colBox, float x1, float y1, float x2, float y2)
{   


    return false;

}


////Render Code

void draw()
{

    SDL_RenderClear(game.renderer);


    //render background

    //render map
    renderMap(game.map->ly_head);
    //render static assets??

    //render chars and enemies
    renderChar();

    SDL_RenderPresent(game.renderer);

}
//make sure that layers have disabled visibility if not for rendering


void renderMap(tmx_layer* layers)//linked list of layers
{  
    while (layers) //iterate through list
    {
		if (layers->visible) {
            //if mixed layers
			if (layers->type == L_GROUP) {
				renderMap( layers->content.group_head);
			}
            //object layer
			else if (layers->type == L_OBJGR) {
				draw_objects(layers->content.objgr);
			}
            //image layer
			else if (layers->type == L_IMAGE) {
				draw_image_layer(layers->content.image);
			}
            //tile layer
			else if (layers->type == L_LAYER) {
				draw_layer(layers);
			}
		}
		layers = layers->next;
	}
}

void drawPolyline(double ** points, double x, double y, int pointsc)
{   
    for(int i = 1; i < pointsc; i++)
    {
        SDL_RenderDrawLine(game.renderer, x+points[i-1][0], y+points[i-1][1], x+points[i][0], y+points[i][1]);
    }

}

void drawPolygon(double ** points, double x, double y, int pointsc)
{
    drawPolyline(points, x, y, pointsc);//draw all but last line
    if(pointsc > 2)//line for first and last point
    {
        SDL_RenderDrawLine(game.renderer, x+points[0][0], y+points[0][1], x+points[pointsc-1][0], y+points[pointsc-1][1]);
    }
}

void draw_objects(tmx_object_group *objGroup)
{
    SDL_Rect rect;
    tmx_col_bytes col= tmx_col_to_bytes(objGroup->color);
    SDL_SetRenderDrawColor(game.renderer, col.r, col.g, col.b, col.a);//set color for drawing lines etc.
    tmx_object *head = objGroup->head;

    while(head)//iterate linked list
    {
        if(head->visible)//only render if object is visible
        {
            if(head->obj_type == OT_SQUARE)
            {
                rect.x = head->x;
                rect.y = head->y;
				rect.w = head->width;
                rect.h = head->height;

				SDL_RenderDrawRect(game.renderer, &rect);
            }
            else if(head->obj_type == OT_POLYGON)
            {
                drawPolygon(head->content.shape->points, head->x, head->y, head->content.shape->points_len);        
            }
            else if(head->obj_type == OT_POLYLINE)
            {
                drawPolyline(head->content.shape->points, head->x, head->y, head->content.shape->points_len);
            }
            else if(head->obj_type == OT_ELLIPSE)
            {
                //implement drawEllipse
            }
        }
    }
}

void draw_image_layer(tmx_image *image)
{
	SDL_Rect dim;
	dim.x = dim.y = 0;

	SDL_Texture *texture = (SDL_Texture*)image->resource_image; // Texture loaded by libTMX
	SDL_QueryTexture(texture, NULL, NULL, &(dim.w), &(dim.h));
	SDL_RenderCopy(game.renderer, texture, NULL, &dim);
}

void draw_tile(void *image, unsigned int sx, unsigned int sy, unsigned int sw, unsigned int sh,
               unsigned int dx, unsigned int dy, float opacity, unsigned int flags)
{
	SDL_Rect src_rect, dest_rect;
	src_rect.x = sx;
	src_rect.y = sy;
	src_rect.w = dest_rect.w = sw;
	src_rect.h = dest_rect.h = sh;
	dest_rect.x = dx;
	dest_rect.y = dy;
	SDL_RenderCopy(game.renderer, (SDL_Texture*)image, &src_rect, &dest_rect);
}

void draw_layer(tmx_layer* layer)
{ 
	unsigned int gid, x, y, w, h, flags;
    float op =  layer->opacity;
    tmx_tileset *ts;
    tmx_image *im;
    void* image;

    for(int cell_y = 0; cell_y < game.map->height; cell_y++) 
    {
        for(int cell_x = 0; cell_x < game.map->width; cell_x++) 
        {
            gid = (layer->content.gids[cell_y * game.map->width + cell_x]) & TMX_FLIP_BITS_REMOVAL;
            if(game.map->tiles[gid] != NULL) 
            {
                ts = game.map->tiles[gid]->tileset;
                if(ts == NULL)
                {
                    printf("lasldasld");
                    exit(EXIT_FAILURE);
                }
                im = game.map->tiles[gid]->image;
                x = game.map->tiles[gid]->ul_x;
                y = game.map->tiles[gid]->ul_y;
                w = ts->tile_width;
                h = ts->tile_height;

                if(im)
                {
                    image = im->resource_image;
                }
                else
                {
                    image = ts->image->resource_image;
                }
                flags = (layer->content.gids[(cell_y*game.map->width)+cell_x]) & ~TMX_FLIP_BITS_REMOVAL;
                draw_tile(image, x, y, w, h, cell_x*w, cell_y*h, op, flags);
            }
        }
    }


}

void renderChar()
{

    SDL_Rect masd;
    masd.h = mainChar.spriteClip->h*2;
    masd.w = mainChar.spriteClip->w*2;
    masd.x = mainChar.xPosition;
    masd.y = mainChar.yPosition;
    int i = 0;
    bool flip = false;

    if(mainChar.spriteState == DOWN_IDLE)
    {
        i = 0; 
        masd.h -= 3;
        masd.w -= 3;
    }

    else if(DIAG_DOWN<= mainChar.spriteState && mainChar.spriteState <= 4){i = 1;} 
    else if(DIAG_UP<= mainChar.spriteState && mainChar.spriteState <= 8){i = 2;} 
    else if(UP_WALK<= mainChar.spriteState && mainChar.spriteState <= 12){i = 3;} 
    else if(RIGHT_WALK<= mainChar.spriteState && mainChar.spriteState <= 16){i = 4;}
    else if(DOWN_WALK<= mainChar.spriteState && mainChar.spriteState <= 20){i = 5;}
    else if(LEFT_WALK<= mainChar.spriteState && mainChar.spriteState <= 24){i = 4; flip = true;}


    SDL_RenderCopyEx(game.renderer, mainChar.mTexture[i], &mainChar.spriteClip[mainChar.spriteState], &masd, 0, NULL, flip);
}

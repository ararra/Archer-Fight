#include "update.h"



bool collfunc(){  //TODO: Finish code.
    tmx_object * collListIter = game.mapCollisions->content.objgr->head;
    while (collListIter->next != NULL) {
        if (collision(collListIter)){
            printf("player pos:%d, %d \t building pos: %f, %f \n", gay.x, gay.y, collListIter->x, collListIter->y);

            return true;
        }
        collListIter = collListIter->next;
    }
    return false;

}
//  Basic collision check for buildings this will probably be moved to its own function and this one will manage more than just stationary map objects.
//  check if char is hitting a side of a collision box.
// The code seems right but there is an issue with the tmx mao i think.    
bool collision(tmx_object* collObject){
    if(gay.x +gay.w > collObject->x && gay.x < collObject->x+collObject->width){
        if(gay.y +gay.h >collObject->y && gay.y < collObject->y + collObject->height){
            return true;
        }
    }
    return false;
}
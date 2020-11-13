#include "functionPrototypes.h"
//hit box of quick sort button
bool hitboxQuick(ALLEGRO_MOUSE_STATE mouState)
{
    if (mouState.x >= SCREENWIDTH/16 && mouState.y >= SCREENHEIGHT/2 && mouState.x <= SCREENWIDTH/4+SCREENWIDTH/16 && mouState.y <= SCREENHEIGHT/4*3) {
        return true;
    }
    return false;
}
//hit box of merge sort button
bool hitboxMerge(ALLEGRO_MOUSE_STATE mouState)
{
    if (mouState.x >= SCREENWIDTH/4+SCREENWIDTH/16*2 && mouState.y >= SCREENHEIGHT/2 && mouState.x <= SCREENWIDTH/4*2+SCREENWIDTH/16*2 && mouState.y <= SCREENHEIGHT/4*3) {
        return true;
    }
    return false;
}
//hit box selection sort button
bool hitboxSelection(ALLEGRO_MOUSE_STATE mouState)
{
    if (mouState.x >= SCREENWIDTH/4*2+SCREENWIDTH/16*3 && mouState.y >= SCREENHEIGHT/2 && mouState.x <= SCREENWIDTH/4*3+SCREENWIDTH/16*3 && mouState.y <= SCREENHEIGHT/4*3) {
        return true;
    }
    return false;
}
//hit box return button
bool hitboxReturn(ALLEGRO_MOUSE_STATE mouState)
{
    if (mouState.x >= 0 && mouState.y >= 50 && mouState.x <= 50 && mouState.y <= 100) {
        return true;
    }
    return false;
}
//hit box new data set button
bool hitboxNewData(ALLEGRO_MOUSE_STATE mouState)
{
    if (mouState.x >= SCREENWIDTH/2-SCREENWIDTH/16 && mouState.y >= SCREENHEIGHT/2+SCREENHEIGHT/3 && mouState.x <= SCREENWIDTH/2+SCREENWIDTH/16 && mouState.y <= SCREENHEIGHT/2+SCREENHEIGHT/3+32) {
        return true;
    }
    return false;
}

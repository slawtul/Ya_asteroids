#ifndef BULLET_HELPERS_H
#define BULLET_HELPERS_H


#include "bullet.h"


struct bullet_helpers
{
    // calculates bullet motion from spaceship motion
    obj_motion calc_motion(const obj_motion& spaceship_motion);

    // calculates bullet rect from spaceship rect
    SDL_Rect calc_rect(const SDL_Rect& spaceship_rect);
};


#endif //BULLET_HELPERS_H

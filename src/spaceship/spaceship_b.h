#ifndef SPACESHIP_B_H
#define SPACESHIP_B_H


#include <SDL_render.h>
#include "images/texture_shelf.h"
#include "shared/gfx_helpers.h"
#include "shared/physics_helpers.h"
#include "shared/obj_meta.h"
#include "shared/obj_motion.h"
#include "init/constants.h"


struct spaceship_b
{
    spaceship_b(SDL_Renderer* renderer, SDL_Rect rect, texture_shelf* ts, obj_meta meta, obj_motion motion);

    void input();

    void physics();

    void gfx();

    void update();

    SDL_Renderer* renderer;
    SDL_Rect rect;
    texture_shelf* ts;
    obj_meta meta;
    obj_motion motion;
};


#endif //SPACESHIP_B_H

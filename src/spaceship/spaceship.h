#ifndef SPACESHIP_H
#define SPACESHIP_H


#include <SDL_render.h>
#include <images/texture_shelf.h>
#include <shared/gfx_helpers.h>
#include <shared/physics_helpers.h>
#include <shared/obj_meta.h>
#include <shared/obj_motion.h>
#include <init/constants.h>


struct spaceship
{
    spaceship(SDL_Renderer *renderer,
        SDL_Rect &rect,
        texture_shelf &ts,
        obj_meta &meta,
        obj_motion &motion);

    void update();

    void input();
    void physics();
    void gfx();

private:
    SDL_Renderer *renderer;
    SDL_Rect rect;
    texture_shelf &ts;
    obj_meta meta;
    obj_motion motion;
};


#endif //SPACESHIP_H

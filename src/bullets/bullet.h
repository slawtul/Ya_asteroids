#ifndef BULLET_H
#define BULLET_H


#include <shared/gfx_helpers.h>
#include <shared/physics_helpers.h>
#include <spaceship/spaceship.h>


struct bullet
{
    bullet(
        SDL_Renderer *renderer,
        SDL_Rect &rect,
        texture_shelf &ts,
        obj_meta &meta,
        obj_motion &motion,
        spaceship &ship);
    void update();

private:
    void input();
    void physics();
    void gfx();

    SDL_Renderer *renderer;
    SDL_Rect rect;
    texture_shelf &ts;
    obj_meta &meta;
    obj_motion &motion;
    spaceship &ship;
};


#endif //BULLET_H

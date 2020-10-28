#ifndef DESTROY_ASTEROIDS_SCENE_H
#define DESTROY_ASTEROIDS_SCENE_H


#include <SDL.h>
#include <vector>
#include <algorithm>
#include <variant>
#include <images/texture_shelf.h>
#include <bullets/bullet.h>
#include <spaceship/spaceship.h>


struct destroy_asteroids_scene
{
    void update(SDL_Event &event,
        SDL_Renderer *renderer,
        texture_shelf &ts,
        std::vector<std::variant<bullet, spaceship>> &game_objects);
};


#endif // DESTROY_ASTEROIDS_SCENE_H

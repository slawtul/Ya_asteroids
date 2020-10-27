#pragma once


#include <SDL.h>
#include <vector>
#include <images/texture_shelf.h>
#include <variant>
#include <game_object.h>


struct destroy_asteroids_scene
{
    void update(
        SDL_Event &event,
        SDL_Renderer *renderer,
        texture_shelf &ts,
        std::vector<std::variant> &game_objects);
};

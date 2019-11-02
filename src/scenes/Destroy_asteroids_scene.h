#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include "Graphics.h"
#include "Game_object.h"
#include "Game_object_utils.h"
#include "Init_SDL2.h"

struct Destroy_asteroids_scene
{
    static void update(SDL_Event &event, Graphics &graphics, std::vector<Game_object> &game_objects, Game_object &bullet)
    {
        SDL_SetRenderDrawColor(graphics.renderer, 0, 0, 0, 255);
        SDL_RenderClear(graphics.renderer);
        SDL_RenderCopy(
            graphics.renderer, graphics.texture_shelf.get_texture("background_01_static"), nullptr, nullptr
        );
        SDL_PollEvent(&event);

        if (is_ENTER_key_pressed()) {
            game_objects.emplace_back(fire_bullet(bullet, game_objects[0]));
        }
        if (is_SPACE_key_pressed()) {
            game_objects.emplace_back(fire_bullet(bullet, game_objects[1]));
        }

        for (auto &game_obj : game_objects) {
            game_obj.update(graphics);
        }

        auto not_active = std::remove_if(
            game_objects.begin(), game_objects.end(),
            [&](const Game_object &obj)
            {
                return !obj.meta.is_active;
            }
        );
        game_objects.erase(not_active, game_objects.end());
    }
};

#pragma once

#include <map>
#include <SDL.h>
#include <init/Init_SDL2.h>
#include "shared/Graphics.h"

struct Texture_shelf
{
    std::map<std::string_view, SDL_Texture *> shelf{};

    SDL_Texture *get_texture(const std::string_view &texture_name)
    {
        return shelf[texture_name];
    }

    void add_image(SDL_Renderer *renderer, const char *texture_name, const char *file)
    {
        Init_SDL2 SDL2;
        auto surface = SDL2.load_image(file);
        auto texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        shelf[texture_name] = texture;
        SDL_LogInfo(0, "Create texture for %s", file);
    }

    void add_initial_images(SDL_Renderer *renderer)
    {
        add_image(renderer, "background_01_static", "resources/background_01_static.jpg");
        add_image(renderer, "bullet_short_single", "resources/bullet_short_single.png");
        add_image(renderer, "DKO-api-X1", "resources/DKO-api-X1.png");
        add_image(renderer, "CX16-X1", "resources/CX16-X1.png");
        add_image(renderer, "WO84-wu-X1", "resources/WO84-wu-X1.png");
        add_image(renderer, "explosion", "resources/explosion.png");
    }

    void destroy_textures()
    {
        for (auto const &[texture_name, texture] : shelf) {
            SDL_DestroyTexture(texture);
        }
        SDL_LogInfo(0, "Destroy all textures");
    }
};
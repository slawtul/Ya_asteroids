#pragma once

#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

struct Texture_shelf
{
    std::map<std::string_view, SDL_Texture *> shelf{};

    SDL_Texture *get_texture(const std::string_view &texture_name);

    void add_image(
        SDL_Renderer *renderer,
        const std::string_view
        &texture_name,
        const std::string_view &file
    );

    void add_initial_images(SDL_Renderer *renderer);

    void destroy_textures();

    SDL_Surface *load_image(const std::string_view &file) const;
};
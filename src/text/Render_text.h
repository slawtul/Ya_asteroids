#pragma once

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

struct Render_text
{
    void render_text(
        SDL_Rect &rect, TTF_Font *font, SDL_Color color, SDL_Renderer *renderer,
        const std::string &text_to_render
    )
    {
        const auto surface = TTF_RenderText_Solid(font, text_to_render.c_str(), color);
        const auto texture = SDL_CreateTextureFromSurface(renderer, surface);

        int rect_w, rect_h;
        SDL_QueryTexture(texture, nullptr, nullptr, &rect_w, &rect_h);
        rect.w = rect_w;
        rect.h = rect_h;

        SDL_RenderCopy(renderer, texture, nullptr, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
};
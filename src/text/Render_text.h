#ifndef RENDER_TEXT_H
#define RENDER_TEXT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

struct Render_text {
  void render(SDL_Rect &rect, TTF_Font *font, SDL_Color color,
              SDL_Renderer *renderer, const std::string_view &text_to_render);
};

#endif // RENDER_TEXT_H

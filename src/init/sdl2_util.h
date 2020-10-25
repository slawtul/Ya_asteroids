#pragma once

#include <SDL.h>

struct sdl2_util
{
  void init(uint32_t flags);
  SDL_Window *create_window(const char *title,
                            int screen_width,
                            int screen_height,
                            uint32_t flags);
  SDL_Renderer *create_renderer(SDL_Window *window, uint32_t flags);
};

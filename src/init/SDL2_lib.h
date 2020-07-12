#pragma once

#include <SDL.h>

struct SDL2_lib {
  void init(const uint32_t flags);

  SDL_Window *create_window(const char *title, int screen_width,
                            int screen_height, const uint32_t flags);

  SDL_Renderer *create_renderer(SDL_Window *window, uint32_t flags);
};

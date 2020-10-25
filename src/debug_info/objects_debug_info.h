#pragma once

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <text/render_text.h>

struct objects_debug_info
{
  uint16_t objs_on_screen;
  uint16_t max_objs_on_screen;

  uint16_t count_objs();
  void render_obj_qty(TTF_Font *font,
                      SDL_Color color,
                      SDL_Renderer *renderer) const;
  void
  render_max_obj_qty(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer);
};

#include "Objects_debug_info.h"

uint16_t Objects_debug_info::count_objs() {
  if (objs_on_screen > max_objs_on_screen) {
    max_objs_on_screen = objs_on_screen;
  }
  return max_objs_on_screen;
}

void Objects_debug_info::render_obj_qty(TTF_Font *font, SDL_Color color,
                                        SDL_Renderer *renderer) const {
  auto rect = SDL_Rect{20, 56, 120, 16};
  Render_text rt;
  rt.render(rect, font, color, renderer,
            "Obj_qty: " + std::to_string(objs_on_screen));
}

void Objects_debug_info::render_max_obj_qty(TTF_Font *font, SDL_Color color,
                                            SDL_Renderer *renderer) {
  auto rect = SDL_Rect{20, 72, 120, 16};
  Render_text rt;
  rt.render(rect, font, color, renderer,
            "Max_qty: " + std::to_string(count_objs()));
}

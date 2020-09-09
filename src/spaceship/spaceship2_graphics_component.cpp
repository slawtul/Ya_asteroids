#include "spaceship2_graphics_component.h"

void spaceship2_graphics_component::update(game_object &obj,
                                           graphics &graphics) {
  obj.rect.x += static_cast<int>(obj.motion.dx);
  obj.rect.y += static_cast<int>(obj.motion.dy);

  auto[x, y] = calc_position_if_edge_screen_reached(
      obj.rect.x, obj.rect.y, obj.rect.w, obj.rect.h, graphics);

  obj.rect.x = x;
  obj.rect.y = y;

  SDL_RenderCopyEx(graphics.renderer,
                   graphics.tex_shelf.get_texture("CX16-X1"), nullptr,
                   &obj.rect, obj.motion.angle + 90, nullptr, SDL_FLIP_NONE);
}

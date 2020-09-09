#include "bullet_graphics_component.h"

void bullet_graphics_component::update(game_object &obj, graphics &graphics) {
  obj.rect.x += static_cast<int>(obj.motion.dx);
  obj.rect.y += static_cast<int>(obj.motion.dy);

  if (off_screen(obj.rect.x, obj.rect.y, graphics)) {
    obj.meta.is_active = false;
    return;
  }

  SDL_RenderCopyEx(graphics.renderer,
                   graphics.texture_shelf.get_texture("bullet_short_single"),
                   nullptr, &obj.rect, obj.motion.angle + 90, nullptr,
                   SDL_FLIP_NONE);
}

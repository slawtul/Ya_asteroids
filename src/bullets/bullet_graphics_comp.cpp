#include "bullet_graphics_comp.h"
#include "graphics_comp.h"

void bullet_graphics_comp::update()
{
  go.rect.x += static_cast<int>(go.motion.dx);
  go.rect.y += static_cast<int>(go.motion.dy);

  if (graphics_comp::off_screen(go.rect.x, go.rect.y, gfx)) {
    go.meta.is_active = false;
    return;
  }

  SDL_RenderCopyEx(gfx.renderer,
                   gfx.tex_shelf.get_texture("bullet_short_single"),
                   nullptr, &go.rect, go.motion.angle + 90, nullptr,
                   SDL_FLIP_NONE);
}
bullet_graphics_comp::bullet_graphics_comp(game_object &go,
                                           const graphics &gfx)
  : go(go), gfx(gfx)
{}

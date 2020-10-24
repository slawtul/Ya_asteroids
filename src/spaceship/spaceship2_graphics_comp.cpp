#include "spaceship2_graphics_comp.h"
#include "graphics_comp.h"

void spaceship2_graphics_comp::update()
{
  go.rect.x += static_cast<int>(go.motion.dx);
  go.rect.y += static_cast<int>(go.motion.dy);

  auto[x, y] = graphics_comp::calc_position_if_edge_screen_reached(
    go.rect.x, go.rect.y, go.rect.w, go.rect.h, gfx);

  go.rect.x = x;
  go.rect.y = y;

  SDL_RenderCopyEx(gfx.renderer,
                   gfx.tex_shelf.get_texture("CX16-X1"), nullptr,
                   &go.rect, go.motion.angle + 90, nullptr, SDL_FLIP_NONE);
}
spaceship2_graphics_comp::spaceship2_graphics_comp(const game_object &go,
                                                   const graphics &gfx)
  : go(go), gfx(gfx)
{}

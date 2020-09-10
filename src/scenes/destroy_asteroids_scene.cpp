#include "destroy_asteroids_scene.h"
#include "game_object_utils.h"
#include <algorithm>

void destroy_asteroids_scene::update(SDL_Event &event, graphics &gfx,
                                     std::vector<game_object> &game_objects) {

  SDL_SetRenderDrawColor(gfx.renderer, 0, 0, 0, 255);
  SDL_RenderClear(gfx.renderer);
  SDL_RenderCopy(gfx.renderer,
                 gfx.tex_shelf.get_texture("background_01_static"), nullptr,
                 nullptr);

  SDL_PollEvent(&event);
  if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RETURN]) {
    game_object_utils gou;
    auto bullet = gou.create_bullet();
    game_objects.emplace_back(
        std::move(gou.fire_bullet(bullet, game_objects[0])));
  }
  if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_SPACE]) {
    game_object_utils gou;
    auto bullet = gou.create_bullet();
    game_objects.emplace_back(
        std::move(gou.fire_bullet(bullet, game_objects[1])));
  }

  // reverse iterator used
  // bullets should be placed under starships
  for (auto it = game_objects.rbegin(); it != game_objects.rend(); ++it) {
    it->update(gfx);
  }

  auto not_active = std::remove_if(game_objects.begin(), game_objects.end(),
                                   [&](const game_object &obj) {
                                     return !obj.meta.is_active;
                                   });
  game_objects.erase(not_active, game_objects.end());
}

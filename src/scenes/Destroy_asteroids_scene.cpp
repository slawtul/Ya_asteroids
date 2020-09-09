#include "Destroy_asteroids_scene.h"
#include "Game_object_utils.h"
#include <algorithm>

void Destroy_asteroids_scene::update(SDL_Event &event, Graphics &graphics,
                                     std::vector<Game_object> &game_objects) {
  SDL_SetRenderDrawColor(graphics.renderer, 0, 0, 0, 255);
  SDL_RenderClear(graphics.renderer);
  SDL_RenderCopy(graphics.renderer,
                 graphics.texture_shelf.get_texture("background_01_static"),
                 nullptr, nullptr);

  SDL_PollEvent(&event);
  if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RETURN]) {
    Game_object_utils gou;
    auto bullet = gou.create_bullet();
    game_objects.emplace_back(
        std::move(gou.fire_bullet(bullet, game_objects[0])));
  }
  if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_SPACE]) {
    Game_object_utils gou;
    auto bullet = gou.create_bullet();
    game_objects.emplace_back(
        std::move(gou.fire_bullet(bullet, game_objects[1])));
  }

  // reverse iterator used
  // bullets should be placed under starships
  for (auto it = game_objects.rbegin(); it != game_objects.rend(); ++it) {
    it->update(graphics);
  }

  auto not_active = std::remove_if(game_objects.begin(), game_objects.end(),
                                   [&](const Game_object &obj) {
                                     return !obj.meta.is_active;
                                   });
  game_objects.erase(not_active, game_objects.end());
}

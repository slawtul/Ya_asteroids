#include "destroy_asteroids_scene.h"


auto call_update = [](auto &game_obj)
{
  return game_obj.update();
};

void destroy_asteroids_scene::update(SDL_Event &event,
    SDL_Renderer *renderer,
    texture_shelf &ts,
    std::vector<std::variant<bullet, spaceship>> &game_objects)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,
        ts.get_texture("background_01_static"),
        nullptr,
        nullptr);

    SDL_PollEvent(&event);
//    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_SPACE])
//    {
//        game_object_utils gou{};
//        auto bullet = gou.create_bullet();
//        game_objects.emplace_back(
//            std::move(gou
//                .fire_bullet(bullet, game_objects[1]))); // [1] spaceship 2
//    }

    // main loop which call update() method on each game object
    // ---
    // reverse iterator used cause bullets should be placed under starships

    SDL_Rect s_rect{ 0, 200, 64, 64 };
    obj_meta s_meta{};
    obj_motion s_motion{};
    spaceship s{ renderer, s_rect, ts, s_meta, s_motion };
    game_objects.emplace_back(s);

    for (auto &game_obj : game_objects)
    {
        std::visit(call_update, game_obj);
    }

//    const auto not_active = std::remove_if(
//        game_objects.begin(), game_objects.end(),
//        [&](const game_object &item_)
//        {
//          return !item_.meta.is_active;
//        });
//    game_objects.erase(not_active, game_objects.end());
}

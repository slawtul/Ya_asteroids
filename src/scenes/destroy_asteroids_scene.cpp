#include "destroy_asteroids_scene.h"


auto call_update = [](auto &game_obj)
{
  return game_obj.update();
};

void destroy_asteroids_scene::update(SDL_Event &event,
    SDL_Renderer *renderer,
    texture_shelf &ts,
    std::vector<variant_game_obj> &game_objects)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,
        ts.get_texture("background_01_static.jpg"),
        nullptr,
        nullptr);

    SDL_PollEvent(&event);
//    SDL_Rect b_rect{ 0, 0, 4, 20 };
//    obj_meta b_meta{};
//    obj_motion b_motion{};
//    bullet b{ renderer, b_rect, ts, b_meta, b_motion, s };


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

    spaceship_a ship{ renderer, { 0, 100, 64, 64 }, ts, {}, {}};
    game_objects.emplace_back(ship);
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

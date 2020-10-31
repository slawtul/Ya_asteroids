
#include "destroy_asteroids_scene.h"


auto call_update = [](auto& game_obj) {
    return game_obj.update();
};

auto is_active = [](auto& game_obj) {
    return game_obj.meta.is_active;
};

void destroy_asteroids_scene::update(SDL_Event& event,
        SDL_Renderer* renderer,
        texture_shelf* ts,
        std::vector<variant_game_obj>& game_objects)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, ts->get_texture("background_01_static.jpg"), nullptr, nullptr);

    SDL_PollEvent(&event);
    bullet_helpers bh{};

    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_SPACE]) {
        auto const spaceship = std::get<spaceship_a>(game_objects[0]);
        auto const rect = bh.calc_rect(spaceship.rect);
        auto const motion = bh.calc_motion(spaceship.motion);
        bullet b{ renderer, rect, ts, {}, motion };
        game_objects.emplace_back(b);
    }

    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RETURN]) {
        auto const spaceship = std::get<spaceship_b>(game_objects[1]);
        auto const rect = bh.calc_rect(spaceship.rect);
        auto const motion = bh.calc_motion(spaceship.motion);
        bullet b{ renderer, rect, ts, {}, motion };
        game_objects.emplace_back(b);
    }

    // main loop which call update() method on each game object
    // ---
    // reverse iterator used cause bullets should be placed under starships
    for (auto& game_obj : game_objects) {
        std::visit(call_update, game_obj);
    }

    // before leaving updating scene method remove all inactive game objects
    const auto not_active = std::remove_if(game_objects.begin(), game_objects.end(),
            [](const auto& game_obj) {
                return !std::visit(is_active, game_obj);
            });
    game_objects.erase(not_active, game_objects.end());
}

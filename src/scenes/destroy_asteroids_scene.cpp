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
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_SPACE]) {
        obj_motion motion{};
        motion.acceleration = 32;
        SDL_Rect rect{ 0, 0, 4, 20 };
        spaceship_a spaceship = std::get<spaceship_a>(game_objects[0]);
        rect.x = spaceship.rect.x + (spaceship.rect.w - rect.w) / 2;
        rect.y = spaceship.rect.y + (spaceship.rect.h - rect.h) / 2;
        motion.angle = spaceship.motion.angle;
        motion.max_speed = spaceship.motion.max_speed * 4;

        bullet b{ renderer, rect, ts, {}, motion };
        game_objects.emplace_back(b);
    }

    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RETURN]) {
        obj_motion motion{};
        motion.acceleration = 32;
        SDL_Rect rect{ 0, 0, 4, 20 };
        spaceship_b spaceship = std::get<spaceship_b>(game_objects[1]);
        rect.x = spaceship.rect.x + (spaceship.rect.w - rect.w) / 2;
        rect.y = spaceship.rect.y + (spaceship.rect.h - rect.h) / 2;
        motion.angle = spaceship.motion.angle;
        motion.max_speed = spaceship.motion.max_speed * 4;

        bullet b{ renderer, rect, ts, {}, motion };
        game_objects.emplace_back(b);
    }

    // main loop which call update() method on each game object
    // ---
    // reverse iterator used cause bullets should be placed under starships
    for (auto& game_obj : game_objects) {
        std::visit(call_update, game_obj);
    }

    const auto not_active = std::remove_if(
            game_objects.begin(),
            game_objects.end(),
            [](const auto& game_obj) {
                return !std::visit(is_active, game_obj);
            });
    game_objects.erase(not_active, game_objects.end());
}

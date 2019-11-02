#include "spaceship/Spaceship1_input_component.h"
#include "spaceship/Spaceship1_physics_component.h"
#include "spaceship/Spaceship1_graphics_component.h"
#include "spaceship/Spaceship2_input_component.h"
#include "spaceship/Spaceship2_physics_component.h"
#include "spaceship/Spaceship2_graphics_component.h"

#include "bullets/Bullet_input_component.h"
#include "bullets/Bullet_graphics_component.h"
#include "bullets/Bullet_physics_component.h"

#include "scenes/Destroy_asteroids_scene.h"
#include "scenes/Avoid_asteroids_scene.h"
#include "scenes/Control_spaceships_scene.h"
#include "scenes/Two_spaceships_scene.h"

#include "init/Init_SDL2.h"
#include "text/Render_text.h"
#include "debug_info/Frames_debug_info.h"
#include "debug_info/Objects_debug_info.h"
#include "debug_info/Graphics_debug_info.h"

int main(int argc, char *argv[])
{
    SDL_LogInfo(0, "Program parameters: argc %d", argc);
    SDL_LogInfo(0, "Program parameters: argv %s", *argv);

    Init_SDL2::init_SDL2(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();

    const auto window = Init_SDL2::create_window(
        "YA Asteroids", 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_ALLOW_HIGHDPI
    );
    const auto renderer = Init_SDL2::create_renderer(
        window, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    Graphics_debug_info::log_screen_size(renderer);

    Texture_shelf tex_shelf;
    tex_shelf.add_initial_images(renderer);
    auto graphics = Graphics{renderer, tex_shelf};

    // Create spaceship 1
    Spaceship1_input_component sp1_input;
    Spaceship1_physics_component sp1_physics;
    Spaceship1_graphics_component sp1_gfx;
    auto spaceship1 = create_spaceship1(sp1_input, sp1_physics, sp1_gfx);

    // Create spaceship 2
    Spaceship2_input_component sp2_input;
    Spaceship2_physics_component sp2_physics;
    Spaceship2_graphics_component sp2_gfx;
    auto spaceship2 = create_spaceship2(sp2_input, sp2_physics, sp2_gfx);

    // Create bullet
    Bullet_input_component bullet_input;
    Bullet_physics_component bullet_physics;
    Bullet_graphics_component bullet_gfx;
    auto bullet = create_bullet(bullet_input, bullet_physics, bullet_gfx);

    // Add spaceships
    auto game_objects = std::vector<Game_object>{spaceship1, spaceship2};

    #ifdef DEBUG
    const auto font = TTF_OpenFont("./resources/terminus.ttf", 16);
    const auto white = SDL_Color{255, 255, 255, 127};
    Frames_debug_info frames_debug_info;
    Objects_debug_info objects_debug_info;
    #endif

    // Start: game loop
    SDL_Event event;
    while (true) {

        #ifdef DEBUG
        frames_debug_info.current_time = SDL_GetTicks();
        #endif

        {
            if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_ESCAPE]) {
                break;
            }
            Destroy_asteroids_scene::update(event, graphics, game_objects, bullet);
        }

        #ifdef DEBUG
        frames_debug_info.render_frames_per_second(font, white, graphics.renderer);
        frames_debug_info.render_min_frames(font, white, graphics.renderer);
        objects_debug_info.objects_on_screen = game_objects.size();
        objects_debug_info.render_max_obj_quantity(font, white, graphics.renderer);
        objects_debug_info.render_obj_quantity(font, white, graphics.renderer);
        #endif

        // Render all
        SDL_RenderPresent(graphics.renderer);
    }
    // End: game loop

    // Free memory
    game_objects.clear();
    graphics.texture_shelf.destroy_textures();
    SDL_FreeSurface(SDL_GetWindowSurface(window));
    SDL_DestroyRenderer(graphics.renderer);
    SDL_DestroyWindow(window);

    #ifdef DEBUG
    SDL_LogInfo(0, "Max objects qty: %d", static_cast<int>(objects_debug_info.calc_max_objects_on_screen()));
    SDL_LogInfo(0, "Stop game");
    #endif

    IMG_Quit();
    SDL_Quit();

    return 0;
}

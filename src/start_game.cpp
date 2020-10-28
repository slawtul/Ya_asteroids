#include "debug_info/graphics_debug.h"
#include "init/sdl2_util.h"
#include "scenes/destroy_asteroids_scene.h"
#include "text/render_text.h"


#ifdef DEBUG
#include "debug_info/frames_debug.h"
#include "debug_info/objects_debug.h"
#endif


int main(int argc, char *argv[])
{
    SDL_LogInfo(0, "Program parameters: argc %d", argc);
    SDL_LogInfo(0, "Program parameters: argv %s", *argv);

    sdl2_util sdl2{};
    sdl2.init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();

    const auto window = sdl2.create_window("YA Asteroids",
        1920,
        1080,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

    const auto renderer = sdl2.create_renderer(window, SDL_RENDERER_ACCELERATED);

    graphics_debug gd{};
    gd.log_screen_size(renderer);

    texture_shelf ts{};
    ts.add_init_images(renderer);

    std::vector<game_object_type> game_objects;
    game_objects.reserve(20000);

    SDL_Rect s_rect{ 0, 100, 64, 64 };
    obj_meta s_meta{};
    obj_motion s_motion{};
    spaceship s{ renderer, s_rect, ts, s_meta, s_motion };

    SDL_Rect b_rect{ 0, 0, 4, 20 };
    obj_meta b_meta{};
    obj_motion b_motion{};
    bullet b{ renderer, b_rect, ts, b_meta, b_motion, s };

    game_objects.emplace_back(b);
    game_objects.emplace_back(s);

    #ifdef DEBUG
    const auto font = TTF_OpenFont("./resources/terminus.ttf", 16);
    const auto white = SDL_Color{ 255, 255, 255, 127 };
    frames_debug fd{};
    objects_debug od{};
    #endif

    // start: game loop
    destroy_asteroids_scene scene{};
    SDL_Event event{};
    while (true)
    {
        #ifdef DEBUG
        fd.current_time = SDL_GetTicks();
        #endif

        if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_ESCAPE])
        {
            break;
        }
        scene.update(event, renderer, ts, game_objects);

        #ifdef DEBUG
        fd.render_frames_per_sec(font, white, renderer);
        fd.render_min_frames(font, white, renderer);
        od.objs_on_screen = game_objects.size();
        od.render_max_obj_qty(font, white, renderer);
        od.render_obj_qty(font, white, renderer);
        #endif

        // render all
        SDL_RenderPresent(renderer);
    }
    // end: game loop

    #ifdef DEBUG
    SDL_LogInfo(0, "Max objects qty: %d", static_cast<int>(od.max_objs_on_screen));
    SDL_LogInfo(0, "Avg FPS: %.2f", fd.frames_per_sec);
    SDL_LogInfo(0, "Stop game");
    TTF_CloseFont(font);
    #endif

    // free memory
    game_objects.clear();
    ts.destroy_textures();
    SDL_FreeSurface(SDL_GetWindowSurface(window));
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}

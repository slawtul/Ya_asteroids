#include "debug_info/graphics_debug_info.h"
#include "init/sdl2_util.h"
#include "scenes/destroy_asteroids_scene.h"
#include "shared/game_object_utils.h"
#include "text/render_text.h"

#ifdef DEBUG
#include "debug_info/frames_debug_info.h"
#include "debug_info/objects_debug_info.h"
#endif

int main(int argc, char* argv[])
{
    SDL_LogInfo(0, "Program parameters: argc %d", argc);
    SDL_LogInfo(0, "Program parameters: argv %s", *argv);

    sdl2_util sdl2{};
    sdl2.init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();

    const auto window = sdl2.create_window(
      "YA Asteroids",
      1920,
      1080,
      SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

    const auto renderer = sdl2.create_renderer(
      window,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    graphics_debug_info gdi{};
    gdi.log_screen_size(renderer);

    texture_shelf ts{};
    ts.add_init_images(renderer);
    graphics gfx{ renderer, ts };

    std::vector<game_object> game_objects;
    game_objects.reserve(600);
    game_object_utils gou{};
    game_objects.emplace_back(gou.create_spaceship1());
    game_objects.emplace_back(gou.create_spaceship2());

    #ifdef DEBUG
    const auto font = TTF_OpenFont("./resources/terminus.ttf", 16);
    const auto white = SDL_Color{ 255, 255, 255, 127 };
    frames_debug_info fdi{};
    objects_debug_info odi{};
    #endif

    // start: game loop
    destroy_asteroids_scene scene{};
    SDL_Event event{};
    while (true)
    {
        #ifdef DEBUG
        fdi.current_time = SDL_GetTicks();
        #endif

        if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_ESCAPE])
        {
            break;
        }
        scene.update(event, gfx, game_objects);

        #ifdef DEBUG
        fdi.render_frames_per_sec(font, white, gfx.renderer);
        fdi.render_min_frames(font, white, gfx.renderer);
        odi.objs_on_screen = game_objects.size();
        odi.render_max_obj_qty(font, white, gfx.renderer);
        odi.render_obj_qty(font, white, gfx.renderer);
        #endif

        // render all
        SDL_RenderPresent(gfx.renderer);
    }
    // end: game loop

    #ifdef DEBUG
    SDL_LogInfo(
      0,
      "Max objects qty: %d",
      static_cast<int>(odi.max_objs_on_screen));
    SDL_LogInfo(0, "Avg FPS: %.2f", fdi.frames_per_sec);
    SDL_LogInfo(0, "Stop game");
    TTF_CloseFont(font);
    #endif

    // free memory
    game_objects.clear();
    gfx.tex_shelf.destroy_textures();
    SDL_FreeSurface(SDL_GetWindowSurface(window));
    SDL_DestroyRenderer(gfx.renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}

#include "init/Init_SDL2.h"
#include "text/Render_text.h"
#include "spaceship/Spaceship1_input_component.h"
#include "scenes/Destroy_asteroids_scene.h"
#include "debug_info/Graphics_debug_info.h"
#ifdef DEBUG
#include "debug_info/Frames_debug_info.h"
#include "debug_info/Objects_debug_info.h"
#endif

int main(int argc, char *argv[])
{
    SDL_LogInfo(0, "Program parameters: argc %d", argc);
    SDL_LogInfo(0, "Program parameters: argv %s", *argv);

    Init_SDL2 SDL2;
    SDL2.init_SDL2(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();

    const auto window = SDL2.create_window(
        "YA Asteroids", 1920, 1080, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
    );
    const auto renderer = SDL2.create_renderer(
        window, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    Graphics_debug_info gdi;
    gdi.log_screen_size(renderer);

    Texture_shelf tex_shelf;
    tex_shelf.add_initial_images(renderer);
    auto graphics = Graphics{renderer, tex_shelf};

    Game_object_utils gou;
    auto sp1 = gou.create_spaceship1();
    auto sp2 = gou.create_spaceship2();
    auto game_objects = std::vector<Game_object>();
    game_objects.emplace_back(std::move(sp1));
    game_objects.emplace_back(std::move(sp2));

    #ifdef DEBUG
    const auto font = TTF_OpenFont("./resources/terminus.ttf", 16);
    const auto white = SDL_Color{255, 255, 255, 127};
    Frames_debug_info fdi;
    Objects_debug_info odi;
    #endif

    // Start: game loop
    Destroy_asteroids_scene scene;
    SDL_Event event;
    while (true) {

        #ifdef DEBUG
        fdi.current_time = SDL_GetTicks();
        #endif

        if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_ESCAPE]) {
            break;
        }
        scene.update(event, graphics, game_objects);

        #ifdef DEBUG
        fdi.render_frames_per_second(font, white, graphics.renderer);
        fdi.render_min_frames(font, white, graphics.renderer);
        odi.objects_on_screen = game_objects.size();
        odi.render_max_obj_quantity(font, white, graphics.renderer);
        odi.render_obj_quantity(font, white, graphics.renderer);
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
    SDL_LogInfo(0, "Max objects qty: %d", static_cast<int>(odi.max_objects_on_screen));
    SDL_LogInfo(0, "Avg FPS: %.2f", fdi.frames_per_second);
    SDL_LogInfo(0, "Stop game");
    #endif

    IMG_Quit();
    SDL_Quit();

    return 0;
}

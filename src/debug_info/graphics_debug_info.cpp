#include "graphics_debug_info.h"

void graphics_debug_info::log_screen_size(SDL_Renderer* renderer)
{
    int width{}, height{};
    int result = SDL_GetRendererOutputSize(renderer, &width, &height);
    if (result != 0)
    {
        SDL_Log("Unable to get render output size %s", SDL_GetError());
        SDL_Quit();
    }
    SDL_LogInfo(0, "Init screen size %dx%d", width, height);
}

#ifndef GRAPHICS_DEBUG_INFO_H
#define GRAPHICS_DEBUG_INFO_H

#include <SDL.h>

struct graphics_debug_info
{
    void log_screen_size(SDL_Renderer* renderer);
};

#endif // GRAPHICS_DEBUG_INFO_H

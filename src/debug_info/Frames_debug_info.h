#pragma once

#include <string>
#include <SDL_ttf.h>
#include "text/Render_text.h"

struct Frames_debug_info
{
    Uint32 current_time{0};
    Uint32 last_time{0};
    Uint32 frame_delta_time{0};

    double frame_time{0.0};
    double frames_per_second{0.0};
    double min_fps{0};

    double calc_frames_per_second()
    {
        frame_time = 0.2 * calc_frame_delta_time() + 0.8 * frame_time;
        frames_per_second = 1000.0 / frame_time;
        return frames_per_second;
    }

    double calc_frame_delta_time()
    {
        frame_delta_time = current_time - last_time;
        last_time = current_time;
        return frame_delta_time;
    }

    double calc_min_frames_per_second()
    {
        if (min_fps <= 0) min_fps = frames_per_second;
        if (min_fps > frames_per_second) min_fps = frames_per_second;
        if (min_fps < frames_per_second * 85 / 100) min_fps = 0;
        return min_fps;
    }

    void render_frames_per_second(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer)
    {
        auto rect = SDL_Rect{20, 24, 120, 16};
        render_text(
            rect, font, color, renderer, "Avg_fps: " + std::to_string(calc_frames_per_second())
        );
    }

    void render_min_frames(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer)
    {
        auto rect = SDL_Rect{20, 40, 120, 16};
        render_text(
            rect, font, color, renderer, "Min_fps: " + std::to_string(calc_min_frames_per_second())
        );
    }
};

#pragma once

#include <string>
#include <SDL_ttf.h>
#include "text/Render_text.h"

struct Frames_debug_info
{
    uint32_t current_time{0};
    uint32_t last_time{0};
    uint32_t frame_delta_time{0};

    double frame_time{0.0};
    double frames_per_sec{0.0};
    double min_fps{0};

    double calc_frames_per_sec()
    {
        frame_time = 0.2 * calc_frame_delta_time() + 0.8 * frame_time;
        frames_per_sec = 1000.0 / frame_time;
        return frames_per_sec;
    }

    double calc_frame_delta_time()
    {
        frame_delta_time = current_time - last_time;
        last_time = current_time;
        return frame_delta_time;
    }

    double calc_min_frames_per_sec()
    {
        if (min_fps <= 0) min_fps = frames_per_sec;
        if (min_fps > frames_per_sec) min_fps = frames_per_sec;
        if (min_fps < frames_per_sec * 85 / 100) min_fps = 0;
        return min_fps;
    }

    void render_frames_per_sec(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer)
    {
        auto rect = SDL_Rect{20, 24, 120, 16};
        Render_text rt;
        rt.render_text(
            rect, font, color, renderer, "Avg_fps: " + std::to_string(calc_frames_per_sec())
        );
    }

    void render_min_frames(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer)
    {
        auto rect = SDL_Rect{20, 40, 120, 16};
        Render_text rt;
        rt.render_text(
            rect, font, color, renderer, "Min_fps: " + std::to_string(calc_min_frames_per_sec())
        );
    }
};

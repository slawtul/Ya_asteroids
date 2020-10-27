#include "frames_debug.h"
#include <string>

double frames_debug::calc_frame_delta_time()
{
    frame_delta_time = current_time - last_time;
    last_time = current_time;
    return frame_delta_time;
}

double frames_debug::calc_min_frames_per_sec()
{
    if (min_fps <= 0)
    {
        min_fps = frames_per_sec;
    }
    if (min_fps > frames_per_sec)
    {
        min_fps = frames_per_sec;
    }
    if (min_fps < frames_per_sec * 85 / 100)
    {
        min_fps = 0;
    }
    return min_fps;
}

double frames_debug::calc_frames_per_sec()
{
    frame_time = 0.2 * calc_frame_delta_time() + 0.8 * frame_time;
    frames_per_sec = 1000.0 / frame_time;
    return frames_per_sec;
}

void frames_debug::render_min_frames(
    TTF_Font *font,
    SDL_Color color,
    SDL_Renderer *renderer)
{
    auto rect = SDL_Rect{ 20, 40, 120, 16 };
    render_text rt{};
    rt.render(
        rect,
        font,
        color,
        renderer,
        "Min_fps: " + std::to_string(calc_min_frames_per_sec()));
}

void frames_debug::render_frames_per_sec(
    TTF_Font *font,
    SDL_Color color,
    SDL_Renderer *renderer)
{
    auto rect = SDL_Rect{ 20, 24, 120, 16 };
    render_text rt{};
    rt.render(
        rect,
        font,
        color,
        renderer,
        "Avg_fps: " + std::to_string(calc_frames_per_sec()));
}
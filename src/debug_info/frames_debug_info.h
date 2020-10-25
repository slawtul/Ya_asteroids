#pragma once

#include "text/render_text.h"
#include <SDL_ttf.h>

struct frames_debug_info
{
  uint32_t current_time;
  uint32_t last_time;
  uint32_t frame_delta_time;

  double frame_time;
  double frames_per_sec;
  double min_fps;

  double calc_frames_per_sec();
  double calc_frame_delta_time();
  double calc_min_frames_per_sec();
  void render_frames_per_sec(TTF_Font *font,
                             SDL_Color color,
                             SDL_Renderer *renderer);
  void
  render_min_frames(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer);
};

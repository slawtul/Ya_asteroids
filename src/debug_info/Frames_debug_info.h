#pragma once

#include "text/Render_text.h"
#include <SDL_ttf.h>

struct Frames_debug_info {
  uint32_t current_time{0};
  uint32_t last_time{0};
  uint32_t frame_delta_time{0};

  double frame_time{0.0};
  double frames_per_sec{0.0};
  double min_fps{0};

  double calc_frames_per_sec();

  double calc_frame_delta_time();

  double calc_min_frames_per_sec();

  void render_frames_per_sec(TTF_Font *font, SDL_Color color,
                             SDL_Renderer *renderer);

  void render_min_frames(TTF_Font *font, SDL_Color color,
                         SDL_Renderer *renderer);
};

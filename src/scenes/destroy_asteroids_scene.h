#pragma once

#include <SDL.h>
#include <vector>
#include <variant>
#include <bullets/bullet_input_comp.h>
#include <bullets/bullet_physics_comp.h>
#include <spaceship/spaceship1_input_comp.h>
#include <spaceship/spaceship2_input_comp.h>
#include <spaceship/spaceship1_physics_comp.h>
#include <spaceship/spaceship2_physics_comp.h>
#include <bullets/bullet_graphics_comp.h>
#include <spaceship/spaceship1_graphics_comp.h>
#include <spaceship/spaceship2_graphics_comp.h>
#include "game_object.h"
#include "graphics.h"


using input_var = std::variant<bullet_input_comp,
                               spaceship1_input_comp,
                               spaceship2_input_comp>;

using physics_var = std::variant<bullet_physics_comp,
                                 spaceship1_physics_comp,
                                 spaceship2_physics_comp>;

using gfx_var = std::variant<bullet_graphics_comp,
                             spaceship1_graphics_comp,
                             spaceship2_graphics_comp>;

struct destroy_asteroids_scene
{
  void update(SDL_Event &event, graphics &gfx,
              std::vector<input_var> &goi,
              std::vector<physics_var> &gop,
              std::vector<gfx_var> &gog);
};

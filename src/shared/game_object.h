#pragma once

#include <iostream>
#include <memory>

#include "game_object_meta.h"
#include "game_object_motion.h"
#include "graphics_component.h"
#include "input_component.h"
#include "physics_component.h"

struct game_object {
  std::unique_ptr<input_component> input{};
  std::unique_ptr<physics_component> physics{};
  std::unique_ptr<graphics_component> gfx{};

  game_object_meta meta{};
  game_object_motion motion{};
  SDL_Rect rect{};

  game_object(std::unique_ptr<input_component> input_,
              std::unique_ptr<physics_component> physics_,
              std::unique_ptr<graphics_component> graphics_)

      : input{std::move(input_)}, physics{std::move(physics_)},
        gfx{std::move(graphics_)} {}

  void update(graphics &graphics_);
};

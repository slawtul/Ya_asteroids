#pragma once

#include <iostream>
#include <memory>

#include "Game_object_meta.h"
#include "Game_object_motion.h"
#include "Graphics_component.h"
#include "Input_component.h"
#include "Physics_component.h"

struct Game_object {
  std::unique_ptr<Input_component> input{nullptr};
  std::unique_ptr<Physics_component> physics{nullptr};
  std::unique_ptr<Graphics_component> graphics{nullptr};

  Game_object_meta meta{};
  Game_object_motion motion{};
  SDL_Rect rect{};

  Game_object(std::unique_ptr<Input_component> input_,
              std::unique_ptr<Physics_component> physics_,
              std::unique_ptr<Graphics_component> graphics_)
      : input{std::move(input_)}, physics{std::move(physics_)},
        graphics{std::move(graphics_)} {}

  void update(Graphics &graphics_);
};

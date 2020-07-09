#pragma once

#include <cmath>

struct Game_object;

struct Physics_component
{
  Physics_component() = default;

  virtual ~Physics_component() = default;

  virtual void update(Game_object &obj) = 0;

  static double current_speed(double dx, double dy)
  {
    return std::sqrt(dx * dx + dy * dy);
  }
};

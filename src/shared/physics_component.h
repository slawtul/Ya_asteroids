#pragma once

struct game_object;

struct physics_component {
  physics_component() = default;

  virtual ~physics_component() = default;

  virtual void update(game_object &obj) = 0;

  double current_speed(double dx, double dy);
};

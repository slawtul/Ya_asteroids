#pragma once

struct game_object;

struct input_component {
  input_component() = default;

  virtual ~input_component() = default;

  virtual void update(game_object &obj) = 0;
};

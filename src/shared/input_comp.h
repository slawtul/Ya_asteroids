#pragma once

struct game_object;

struct input_comp {
  input_comp() = default;

  virtual ~input_comp() = default;

  virtual void update(game_object &obj) = 0;
};

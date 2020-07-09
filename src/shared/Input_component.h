#pragma once

struct Game_object;

struct Input_component
{
  Input_component() = default;

  virtual ~Input_component() = default;

  virtual void update(Game_object &obj) = 0;
};

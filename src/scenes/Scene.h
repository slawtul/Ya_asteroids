#pragma once

struct Scene
{
  Scene() = default;

  virtual ~Scene() = default;

  virtual void update() = 0;
};

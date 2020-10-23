#pragma once

struct game_object_motion
{
  double max_speed{};
  double angle{};
  double dx{};
  double dy{};
  double acceleration{0.2};
};

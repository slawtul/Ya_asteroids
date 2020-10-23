#include "physics_comp.h"
#include <cmath>

double physics_comp::current_speed(double dx, double dy)
{
  return std::sqrt(dx * dx + dy * dy);
}

#include "physics_component.h"
#include <cmath>

double physics_component::current_speed(double dx, double dy) {
  return std::sqrt(dx * dx + dy * dy);
}

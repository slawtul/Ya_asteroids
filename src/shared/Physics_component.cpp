#include "Physics_component.h"
#include <cmath>

double Physics_component::current_speed(double dx, double dy) {
  return std::sqrt(dx * dx + dy * dy);
}

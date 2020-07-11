#include <cmath>
#include "Physics_component.h"

double Physics_component::current_speed(double dx, double dy)
{
    return std::sqrt(dx * dx + dy * dy);
}

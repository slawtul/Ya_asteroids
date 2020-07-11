#ifndef SPACESHIP2_GRAPHICS_COMPONENT_H
#define SPACESHIP2_GRAPHICS_COMPONENT_H

#include "Game_object.h"

struct Spaceship2_graphics_component: Graphics_component
{
    void update(Game_object &obj, Graphics &graphics) override;
};

#endif //SPACESHIP2_GRAPHICS_COMPONENT_H
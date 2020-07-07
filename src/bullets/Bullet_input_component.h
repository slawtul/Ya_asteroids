#pragma once

#include "Game_object.h"

struct Bullet_input_component: Input_component
{
    void update([[maybe_unused]] Game_object &obj) override
    {
    }
};

#pragma once

#include <memory>
#include <iostream>

#include "Input_component.h"
#include "Graphics_component.h"
#include "Physics_component.h"
#include "Object_name.h"

struct Meta
{
    Object_name name{Object_name::NONE};

    // You can do physics and graphics calculations on 'active' object only
    // If game object is not active - it's removed from game objects vector
    bool is_active{true};
};

struct Motion
{
    double max_speed{0.0};
    double angle{0.0};
    double dx{0.0};
    double dy{0.0};
    double acceleration{0.2};
};

struct Game_object
{
    Input_component *input_comp{nullptr};
    Physics_component *physics_comp{nullptr};
    Graphics_component *graphics_comp{nullptr};

    Meta meta{};
    Motion motion{};
    SDL_Rect rect{};

    Game_object() = default;

    Game_object(Input_component *input, Physics_component *physics, Graphics_component *graphics)
        : input_comp{input}, physics_comp{physics}, graphics_comp{graphics}
    {
    }

    ~Game_object() = default;

    void update(Graphics &graphics)
    {
        input_comp->update(*this);
        physics_comp->update(*this);
        graphics_comp->update(*this, graphics);
    }
};

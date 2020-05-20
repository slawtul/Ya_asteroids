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
    std::unique_ptr<Input_component> input{nullptr};
    std::unique_ptr<Physics_component> physics{nullptr};
    std::unique_ptr<Graphics_component> graphics{nullptr};

    Meta meta{};
    Motion motion{};
    SDL_Rect rect{};

    Game_object(std::unique_ptr<Input_component> input_,
                std::unique_ptr<Physics_component> physics_,
                std::unique_ptr<Graphics_component> graphics_)
        : input{std::move(input_)},
          physics{std::move(physics_)},
          graphics{std::move(graphics_)}
    {
    }

    void update(Graphics &graphics_)
    {
        input->update(*this);
        physics->update(*this);
        graphics->update(*this, graphics_);
    }
};

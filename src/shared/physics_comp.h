#pragma once

struct game_object;

struct physics_comp
{
    physics_comp() = default;
    virtual ~physics_comp() = default;
    virtual void update(game_object& obj) = 0;
    double current_speed(double dx, double dy);
};

#pragma once

struct Game_object;

struct Physics_component
{
    Physics_component() = default;

    virtual ~Physics_component() = default;

    virtual void update(Game_object &obj) = 0;

    double current_speed(double dx, double dy);
};

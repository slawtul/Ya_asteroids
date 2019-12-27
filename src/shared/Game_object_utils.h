#pragma once

#include "Game_object.h"

struct Game_object_utils
{
    static Game_object create_spaceship1()
    {
        auto input = new Spaceship1_input_component();
        auto physics = new Spaceship1_physics_component();
        auto gfx = new Spaceship1_graphics_component();

        Game_object go{input, physics, gfx};
        go.meta.name = Object_name::SPACESHIP1;
        go.motion.max_speed = 12.0;
        go.rect = {0, 0, 64, 64};
        return go;
    }

    static Game_object create_spaceship2()
    {
        auto input = new Spaceship2_input_component();
        auto physics = new Spaceship2_physics_component();
        auto gfx = new Spaceship2_graphics_component();

        Game_object go{input, physics, gfx};
        go.meta.name = Object_name::SPACESHIP2;
        go.motion.max_speed = 12.0;
        go.rect = {256, 1000, 64, 64};
        return go;
    }

    static Game_object create_bullet()
    {
        auto input = new Bullet_input_component();
        auto physics = new Bullet_physics_component();
        auto gfx = new Bullet_graphics_component();

        Game_object go{input, physics, gfx};
        go.meta.name = Object_name::BULLET;
        go.motion.acceleration = 32;
        go.rect = {0, 0, 4, 20};
        return go;
    }

    static Game_object &fire_bullet(Game_object &bullet, const Game_object &spaceship)
    {
        bullet.rect.x = spaceship.rect.x + (spaceship.rect.w - bullet.rect.w) / 2;
        bullet.rect.y = spaceship.rect.y + (spaceship.rect.h - bullet.rect.h) / 2;
        bullet.motion.angle = spaceship.motion.angle;
        bullet.motion.max_speed = spaceship.motion.max_speed * 4;
        return bullet;
    }
};
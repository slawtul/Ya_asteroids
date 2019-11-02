#pragma once

#include <algorithm>
#include "Game_object.h"

Game_object create_spaceship1(Input_component &input, Physics_component &physics, Graphics_component &gfx)
{
    Game_object go{&input, &physics, &gfx};
    go.meta.name = Object_name::SPACESHIP1;
    go.motion.max_speed = 12.0;
    go.rect = {0, 0, 64, 64};
    return go;
}

Game_object create_spaceship2(Input_component &input, Physics_component &physics, Graphics_component &gfx)
{
    Game_object go{&input, &physics, &gfx};
    go.meta.name = Object_name::SPACESHIP2;
    go.motion.max_speed = 12.0;
    go.rect = {256, 1000, 64, 64};
    return go;
}

Game_object create_bullet(Input_component &input, Physics_component &physics, Graphics_component &gfx)
{
    Game_object go{&input, &physics, &gfx};
    go.meta.name = Object_name::BULLET;
    go.motion.acceleration = 32;
    go.rect = {0, 0, 4, 20};
    return go;
}

Game_object &fire_bullet(Game_object &bullet, const Game_object &spaceship)
{
    bullet.rect.x = spaceship.rect.x + (spaceship.rect.w - bullet.rect.w) / 2;
    bullet.rect.y = spaceship.rect.y + (spaceship.rect.h - bullet.rect.h) / 2;
    bullet.motion.angle = spaceship.motion.angle;
    bullet.motion.max_speed = spaceship.motion.max_speed * 4;
    return bullet;
}

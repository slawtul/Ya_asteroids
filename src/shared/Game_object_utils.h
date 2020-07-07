#pragma once

#include <memory>
#include "Game_object.h"
#include "Spaceship1_input_component.h"
#include "Spaceship1_physics_component.h"
#include "Spaceship1_graphics_component.h"
#include "Spaceship2_input_component.h"
#include "Spaceship2_physics_component.h"
#include "Spaceship2_graphics_component.h"
#include "Bullet_input_component.h"
#include "Bullet_physics_component.h"
#include "Bullet_graphics_component.h"

struct Game_object_utils
{
    Game_object create_spaceship1()
    {
        auto input = std::make_unique<Spaceship1_input_component>();
        auto physics = std::make_unique<Spaceship1_physics_component>();
        auto gfx = std::make_unique<Spaceship1_graphics_component>();

        auto go = Game_object(
            std::move(input),
            std::move(physics),
            std::move(gfx)
        );
        go.meta.name = Object_name::SPACESHIP1;
        go.motion.max_speed = 8.0;
        go.rect = {0, 0, 64, 64};
        return go;
    }

    Game_object create_spaceship2()
    {
        auto input = std::make_unique<Spaceship2_input_component>();
        auto physics = std::make_unique<Spaceship2_physics_component>();
        auto gfx = std::make_unique<Spaceship2_graphics_component>();

        auto go = Game_object(
            std::move(input),
            std::move(physics),
            std::move(gfx)
        );
        go.meta.name = Object_name::SPACESHIP2;
        go.motion.max_speed = 8.0;
        go.rect = {256, 1000, 64, 64};
        return go;
    }

    Game_object create_bullet()
    {
        auto go = Game_object(
            std::make_unique<Bullet_input_component>(),
            std::make_unique<Bullet_physics_component>(),
            std::make_unique<Bullet_graphics_component>()
        );
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
};
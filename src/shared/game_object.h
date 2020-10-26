#pragma once

#include <iostream>
#include <memory>

#include "game_object_meta.h"
#include "game_object_motion.h"
#include "gfx_comp.h"
#include "input_comp.h"
#include "physics_comp.h"

struct game_object
{
    std::unique_ptr<input_comp> input;
    std::unique_ptr<physics_comp> physics;
    std::unique_ptr<gfx_comp> gfx;

    game_object_meta meta;
    game_object_motion motion;
    SDL_Rect rect;

    game_object(
        std::unique_ptr<input_comp> input_,
        std::unique_ptr<physics_comp> physics_,
        std::unique_ptr<gfx_comp> graphics_)
        : input{ std::move(input_) }, physics{ std::move(physics_) },
          gfx{ std::move(graphics_) }
    {
    }

    void update(graphics &graphics_);
};

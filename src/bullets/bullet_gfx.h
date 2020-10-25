#ifndef BULLET_GFX_H
#define BULLET_GFX_H

#include "game_object.h"

struct bullet_gfx : gfx_comp
{
    void update(game_object& obj, graphics& graphics) override;
};

#endif // BULLET_GFX_H

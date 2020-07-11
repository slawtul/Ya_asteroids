#pragma once

#include "Game_object.h"

struct Game_object_utils
{
    Game_object create_spaceship1();

    Game_object create_spaceship2();

    Game_object create_bullet();

    Game_object &fire_bullet(
        Game_object &bullet,
        const Game_object
        &spaceship
    );
};
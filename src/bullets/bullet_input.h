#ifndef BULLET_INPUT_H
#define BULLET_INPUT_H

#include "game_object.h"

struct bullet_input : input_comp
{
    void update(game_object& obj) override;
};

#endif // BULLET_INPUT_H

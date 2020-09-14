#ifndef SPACESHIP1_INPUT_COMPONENT_H
#define SPACESHIP1_INPUT_COMPONENT_H

#include "game_object.h"

struct spaceship1_input_comp : input_comp {

  void update(game_object &obj) override;
};

#endif // SPACESHIP1_INPUT_COMPONENT_H

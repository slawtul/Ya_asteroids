#ifndef SPACESHIP1_INPUT_COMPONENT_H
#define SPACESHIP1_INPUT_COMPONENT_H

#include "game_object.h"

struct spaceship1_input_component : input_component {
  void update(game_object &obj) override;
};

#endif // SPACESHIP1_INPUT_COMPONENT_H

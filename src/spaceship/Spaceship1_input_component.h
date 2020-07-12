#ifndef SPACESHIP1_INPUT_COMPONENT_H
#define SPACESHIP1_INPUT_COMPONENT_H

#include "Game_object.h"

struct Spaceship1_input_component : Input_component {
  void update(Game_object &obj) override;
};

#endif // SPACESHIP1_INPUT_COMPONENT_H

#ifndef SPACESHIP1_INPUT_COMPONENT_H
#define SPACESHIP1_INPUT_COMPONENT_H

#include "game_object.h"

struct spaceship1_input_comp
{
  spaceship1_input_comp(const game_object &go);
  void update();

  game_object go;
};

#endif // SPACESHIP1_INPUT_COMPONENT_H

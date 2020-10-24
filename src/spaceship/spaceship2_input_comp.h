#ifndef SPACESHIP2_INPUT_COMPONENT_H
#define SPACESHIP2_INPUT_COMPONENT_H

#include "game_object.h"

struct spaceship2_input_comp
{
  spaceship2_input_comp(const game_object &go);

  void update();

  game_object go;
};

#endif // SPACESHIP2_INPUT_COMPONENT_H

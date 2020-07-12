#include "Spaceship1_input_component.h"
#include "SDL.h"

void Spaceship1_input_component::update(Game_object &obj) {
  if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RIGHT]) {
    obj.motion.angle += 4.0;
  }
  if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LEFT]) {
    obj.motion.angle -= 4.0;
  }
  if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_UP]) {
    obj.motion.acceleration = 0.6;
    obj.motion.max_speed = 8.0;
  } else {
    obj.motion.acceleration = 0.2;
    obj.motion.max_speed = 6.0;
  }
}

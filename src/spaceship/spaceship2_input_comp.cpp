#include "spaceship2_input_comp.h"
#include "SDL.h"

void spaceship2_input_comp::update()
{
  if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RIGHT]) {
    go.motion.angle += 4.0;
  }
  if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LEFT]) {
    go.motion.angle -= 4.0;
  }
  if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_UP]) {
    go.motion.acceleration = 0.6;
    go.motion.max_speed = 8.0;
  }
  else {
    go.motion.acceleration = 0.2;
    go.motion.max_speed = 6.0;
  }
}
spaceship2_input_comp::spaceship2_input_comp(const game_object &go)
  : go(go)
{}

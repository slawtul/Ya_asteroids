#include "Game_object.h"

void Game_object::update(Graphics &graphics_) {
  input->update(*this);
  physics->update(*this);
  graphics->update(*this, graphics_);
}

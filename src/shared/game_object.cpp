#include "game_object.h"

void game_object::update(graphics& graphics_)
{
		input->update(*this);
		physics->update(*this);
		gfx->update(*this, graphics_);
}

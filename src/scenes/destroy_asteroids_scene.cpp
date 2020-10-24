#include "destroy_asteroids_scene.h"
#include "game_object_utils.h"
#include <algorithm>


auto call_update = [](auto &comp)
{ return comp.update(); };

void destroy_asteroids_scene::update(SDL_Event &event, graphics &gfx,
                                     std::vector<input_var> &goi,
                                     std::vector<physics_var> &gop,
                                     std::vector<gfx_var> &gog)
{
  SDL_SetRenderDrawColor(gfx.renderer, 0, 0, 0, 255);
  SDL_RenderClear(gfx.renderer);
  SDL_RenderCopy(gfx.renderer,
                 gfx.tex_shelf.get_texture("background_01_static"), nullptr,
                 nullptr);

  SDL_PollEvent(&event);

  game_object go{};

  bullet_input_comp bic{go};
  spaceship1_input_comp s1ic{go};
  spaceship2_input_comp s2ic{go};
  goi.emplace_back(bic);
  goi.emplace_back(s1ic);
  goi.emplace_back(s2ic);

  bullet_physics_comp bpc{go};
  spaceship1_physics_comp s1pc{go};
  spaceship2_physics_comp s2pc{go};
  gop.emplace_back(bpc);
  gop.emplace_back(s1pc);
  gop.emplace_back(s1pc);


  bullet_graphics_comp bgc{go, gfx};
  spaceship1_graphics_comp s1gc{go, gfx};
  spaceship2_graphics_comp s2gc{go, gfx};
  gog.emplace_back(bgc);
  gog.emplace_back(s1gc);
  gog.emplace_back(s2gc);

  for (auto &comp : goi) {
    std::visit(call_update, comp);
  }

  for (auto &comp : gop) {
    std::visit(call_update, comp);
  }

  for (auto &comp : gog) {
    std::visit(call_update, comp);
  }



  // main loop which call update() method on each game object
  // ---
  // reverse iterator used cause bullets should be placed under starships
//  for (auto it = game_objects.rbegin(); it != game_objects.rend(); ++it) {
//    it->update(gfx);
//  }

//  const auto not_active = std::remove_if(
//    goi.begin(), goi.end(),
//    [&](const game_object &item_)
//    {
//      return !item_.meta.is_active;
//    });
//  goi.erase(not_active, goi.end());

}

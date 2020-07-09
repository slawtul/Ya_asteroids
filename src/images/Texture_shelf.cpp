#include "Texture_shelf.h"

SDL_Texture *Texture_shelf::get_texture(const std::string_view &texture_name)
{
  return shelf[texture_name];
}

void Texture_shelf::add_image(
  SDL_Renderer *renderer,
  const std::string_view &texture_name,
  const std::string_view &file
)
{
  auto surface = load_image(file);
  auto texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  shelf[texture_name] = texture;
  SDL_LogInfo(0, "Create texture for %s", std::string(file).c_str());
}

void Texture_shelf::add_initial_images(SDL_Renderer *renderer)
{
  add_image(
    renderer,
    "background_01_static",
    "resources/background_01_static.jpg"
  );
  add_image(
    renderer,
    "bullet_short_single",
    "resources/bullet_short_single.png"
  );
  add_image(renderer, "DKO-api-X1", "resources/DKO-api-X1.png");
  add_image(renderer, "CX16-X1", "resources/CX16-X1.png");
  add_image(renderer, "WO84-wu-X1", "resources/WO84-wu-X1.png");
  add_image(renderer, "explosion", "resources/explosion.png");
}

void Texture_shelf::destroy_textures()
{
  for (auto const &[texture_name, texture] : shelf)
  {
    SDL_DestroyTexture(texture);
  }
  SDL_LogInfo(0, "Destroy all textures");
}

SDL_Surface *Texture_shelf::load_image(const std::string_view &file) const
{
  const auto surface = IMG_Load(std::string(file).c_str());
  if (surface == nullptr)
  {
    SDL_Log("Unable to load image %s", std::string(file).c_str());
    SDL_Quit();
  }
  return surface;
}

#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <memory>

#include "SDL.h"
#include "ghost.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(std::vector<std::unique_ptr<GhostAbstract>> &ghosts);
  void RenderPlayableGhost(PlayableGhost *ghost);
  void RenderComputerGhost(ComputerGhost *ghost);

  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif
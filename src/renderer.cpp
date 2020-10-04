#include "renderer.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "ghost.h"

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(std::vector<std::unique_ptr<GhostAbstract>> &ghosts) {
 

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);



for (auto &ghost: ghosts) {

  if (ghost->playable()) {  
    Renderer::RenderPlayableGhost(static_cast<PlayableGhost *>(ghost.get()));

  } else {
    Renderer::RenderComputerGhost(static_cast<ComputerGhost *>(ghost.get()));

  }

}

  SDL_RenderPresent(sdl_renderer);

  
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::RenderPlayableGhost(PlayableGhost *ghost) {

  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = ghost->pos_x() * block.w;
  block.y = ghost->pos_y() * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

}

void Renderer::RenderComputerGhost(ComputerGhost *ghost) {

 std::cout<<ghost->id<<std::endl;
 std::cout<<ghost<<std::endl;

  SDL_Rect block;
  block.w = screen_width / grid_width ;
  block.h = screen_height / grid_height ;

  SDL_SetRenderDrawColor(sdl_renderer, 0xAA  * (ghost->id), 0xBB * (ghost->id), 0xCC * (ghost->id), 0xFF);
  block.x = ghost->pos_x() * block.w ;
  block.y = ghost->pos_y() * block.h ; 
  SDL_RenderFillRect(sdl_renderer, &block);
;
}


#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "ghost.h"

void Controller::ChangeDirection(GhostAbstract &ghost, GhostAbstract::Direction input,
                                 GhostAbstract::Direction opposite) const {
  if (ghost.direction != opposite ) ghost.direction = input;
  return;
}

void Controller::HandleInput(bool &running, GhostAbstract &ghost) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(ghost, GhostAbstract::Direction::kUp,
                          GhostAbstract::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(ghost, GhostAbstract::Direction::kDown,
                          GhostAbstract::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(ghost, GhostAbstract::Direction::kLeft,
                          GhostAbstract::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(ghost, GhostAbstract::Direction::kRight,
                          GhostAbstract::Direction::kLeft);
          break;
      }
    }
  }
}
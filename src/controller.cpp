#include "controller.h"
#include "SDL.h"
#include "ghost.h"
#include <iostream>

void Controller::ChangeDirection(GhostAbstract *ghost,
                                 GhostAbstract::Direction input) const {
  ghost->direction = input;
}

void Controller::HandleInput(bool &running, GhostAbstract *ghost) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
      case SDLK_UP:
        ChangeDirection(ghost, GhostAbstract::Direction::kUp);
        break;

      case SDLK_DOWN:
        ChangeDirection(ghost, GhostAbstract::Direction::kDown);
        break;

      case SDLK_LEFT:
        ChangeDirection(ghost, GhostAbstract::Direction::kLeft);
        break;

      case SDLK_RIGHT:
        ChangeDirection(ghost, GhostAbstract::Direction::kRight);
        break;
      }
    }
  }
}
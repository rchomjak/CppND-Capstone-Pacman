#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ghost.h"

class Controller {
 public:
  void HandleInput(bool &running, GhostAbstract *ghost) const;

 private:
  void ChangeDirection(GhostAbstract &ghost, GhostAbstract::Direction input,
                       GhostAbstract::Direction opposite) const;
};

#endif
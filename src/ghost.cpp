#include "ghost.h"


void ComputerGhost::update() {

    SDL_Point prev_cell{
        static_cast<int>(m_pos_x),
        static_cast<int>(m_pos_y)
    };

    ComputerGhost::update_pos();

    SDL_Point current_cell{
        static_cast<int>(m_pos_x),
        static_cast<int>(m_pos_y)
    };

    if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
        ComputerGhost::update_body(prev_cell, current_cell);
    }

}

void ComputerGhost::update_pos() {

  switch (direction) {
    case Direction::kUp:
      m_pos_x -= m_speed;
      break;

    case Direction::kDown:
      m_pos_y += m_speed;
      break;

    case Direction::kLeft:
      m_pos_x -= m_speed;
      break;

    case Direction::kRight:
      m_pos_x += m_speed;
      break;
  }

  m_pos_x = fmod(m_pos_x + grid_width, grid_width);
  m_pos_y = fmod(m_pos_y + grid_height, grid_height);

}


void ComputerGhost::update_body(SDL_Point &previous, SDL_Point &current) {

    //Orientation for graphics 4 picture of ghosts, so needs to choose correct
    switch(direction) {
        case Direction::kUp:
            body_orient = BodyOrientation::kUp;
            break;

        case Direction::kDown:
            body_orient = BodyOrientation::kDown;
            break;

        case Direction::kLeft:
            body_orient = BodyOrientation::kLeft;
            break;

        case Direction::kRight:
            body_orient = BodyOrientation::kRight;
            break;
    }

}


#ifndef GHOST_H
#define GHOST_H

#include <vector>
#include "SDL.h"


class GhostAbstract
{
    public:    

        enum BodyOrientation {kUp, kDown, kLeft, kRight};
        virtual float pos_x() const { return m_pos_x;}
        virtual float pos_y() const { return m_pos_y;}
        
        virtual void pos_x(float in_pos_x) {m_pos_x = in_pos_x;};
        virtual void pos_y(float in_pos_y) {m_pos_y = in_pos_y;}; 

        virtual bool playable() {return m_playable;}
        virtual void speed(float) = 0;

        virtual void update() = 0;
        
        enum class Direction {kUp, kDown, kLeft, kRight};
       
        float m_pos_x{0.0f};
        float m_pos_y{0.0f};
        
        Direction direction {Direction::kRight};
        bool m_playable = false;
        //Speed of the ghost
        float m_speed{0.1f};

        int grid_width;
        int grid_height;
        BodyOrientation body_orient {BodyOrientation::kRight};

        GhostAbstract(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        m_pos_x(grid_width / 2),
        m_pos_y(grid_height / 2) {}


       virtual ~GhostAbstract() {};

};


class ComputerGhost: public GhostAbstract {
    
    //TODO: Add A* search path 
    //TODO: Random generator of position Position should be choosen

    mutable size_t NO_COMPUTER_GHOSTS = 0; 

    private:
        //Range for A*, how long a computer ghost sees the pacman 
        float m_range{0.0f};
        //No of steps in one direction before the call the random generator to change direction;
        int m_no_steps_one_direction{10};
        //When pacman eats a fruit, the ghosts (computers) can be eaten.
        bool m_is_eatable = false;


    public:

        ComputerGhost(int grid_width, int grid_height):GhostAbstract(grid_width, grid_height), id(NO_COMPUTER_GHOSTS) {
            NO_COMPUTER_GHOSTS++;
        };

        float reach_range() const { return ComputerGhost::m_range;};
        int no_steps_direct () { return ComputerGhost::m_no_steps_one_direction;};
        void speed(float in_speed) override {m_speed = in_speed;};
        void range(float in_range) {m_range = in_range;};
        void update() override;
        void update_pos();
        void update_body(SDL_Point &previous, SDL_Point &current);
        size_t id;
        ~ComputerGhost() = default;

};

class PlayableGhost: public GhostAbstract {

    public:

        PlayableGhost(int grid_width, int grid_height):GhostAbstract(grid_width, grid_height) {m_playable = true;};

        void speed(float in_speed) override {m_speed = in_speed;}
        void update() override;
        void update_pos();
        void update_body(SDL_Point &previous, SDL_Point &current);
        ~PlayableGhost() = default;
};




#endif
#ifndef GHOST_H
#define GHOST_H

class GhostAbstract
{
    public:
    
        virtual float pos_x() const { return m_pos_x;}
        virtual float pos_y() const { return m_pos_y;}
        
        virtual void pos_x(float in_pos_x) {m_pos_x = in_pos_x;};
        virtual void pos_y(float in_pos_y) {m_pos_y = in_pos_y;}; 
        
        virtual bool playable() {return m_playable;}

        virtual void speed(float) = 0;
    
        enum class Direction { kUp, kDown, kLeft, kRight };
       
        float m_pos_x{0.0f};
        float m_pos_y{0.0f};
        
        Direction direction = Direction::kRight;
        bool m_playable = false;
        //Speed of the ghost
        float m_speed{0.1f};
};


class ComputerGhost: private GhostAbstract {
    
    //TODO: Add A* search path 
    //TODO: Random generator of position Position should be choosen
    
    private:
        //Range for A*, how long a computer ghost sees the pacman 
        float m_range{0.0f};
        //No of steps in one direction before the call the random generator to change direction;
        int m_no_steps_one_direction{10};
        //When pacman eats a fruit, the ghosts (computers) can be eaten.
        bool m_is_eatable = false;

    public:

        ComputerGhost() {};

        float reach_range() const { return ComputerGhost::m_range;};
        int no_steps_direct () { return ComputerGhost::m_no_steps_one_direction;};
        void speed(float in_speed) override {m_speed = in_speed;};
        void range(float in_range) {m_range = in_range;};
};

class PlayableGhost: private GhostAbstract {

    public:
        PlayableGhost(){m_playable = true;};

        void speed(float in_speed) override {m_speed = in_speed;}

};




#endif
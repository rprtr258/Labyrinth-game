#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include "Turn.h"
#include "Labyrinth.h"

class PlayerStats {
    public:
        PlayerStats();
        void move(const int&, const int&);
        std::pair<int, int> getCords() const;

        void damage(const int&);
        void heal(const int&);
        const int& getHealth() const;
    private:
        int cordX, cordY;
        int health;
};

#endif

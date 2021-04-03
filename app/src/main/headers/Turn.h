#ifndef TURN_H
#define TURN_H

#include <SFML/Graphics.hpp>

class Turn {
    public:
        Turn();
        void set(sf::Keyboard::Key, int, float, float);
        const sf::Keyboard::Key& getKey() const;
        const int& getWall() const;
        const float& getDirX() const;
        const float& getDirY() const;
    private:
        sf::Keyboard::Key key;
        int wall;
        float dirx, diry;
};

#endif

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "TexturesStorage.h"
#include "PlayerStats.h"
#include "DrawableInterface.h"

class Player:public DrawableInterface {
    public:
        Player();
        Player(float, float);
        void draw(sf::RenderWindow&);
        void move(float x, float y);
        void move(int dx, int dy);
        std::pair<int, int> getPos();
        PlayerStats& getStats();
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        int x, y;
        PlayerStats stats;
        enum MoveDir{UP=1, RIGHT=2, DOWN=3, LEFT=4} dir;
};

#endif

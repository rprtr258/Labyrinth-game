#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "TexturesStorage.h"
#include "PlayerStats.h"

class Player {
    public:
        static void init();
        static void draw(sf::RenderWindow&);
        static void move(float x, float y);
        static void move(int dx, int dy);
        static std::pair<int, int> getPos();
        static PlayerStats& getStats();
    private:
        static sf::Texture texture;
        static sf::Sprite sprite;
        static int x, y;
        static PlayerStats stats;
        static enum MoveDir{UP=1, RIGHT=2, DOWN=3, LEFT=4} dir;
};

#endif

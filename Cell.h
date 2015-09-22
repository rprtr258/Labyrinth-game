#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

#include "TexturesStorage.h"
#include "Constants.h"

class Cell {
    public:
        static const int LEFT = 1, DOWN = 2, RIGHT = 4, UP = 8;
        static const int RU_CORNER = 16, RD_CORNER = 32, LD_CORNER = 64, LU_CORNER = 128;
        Cell();
        ~Cell();
        sf::Sprite &getSprite();
        void setType(int newType);
        int getType();
        void addWall(int wall);
        void removeWall(int wall);
        void addCorner(int corner);
        void removeCorner(int corner);
        bool getWall(const int &wall);
        void draw(sf::RenderWindow &window);
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        int type;
        //type - _ _ _ _ - _ _ _ _ - 0001 - 0000
        //type - ??????? - ??????? - углы - стены
};

#endif

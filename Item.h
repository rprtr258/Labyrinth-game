#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>

#include "TexturesStorage.h"

class Item {
    public:
        enum Type{Empty, Weapon, Ammo};
        Item();
        Item(const int&, const int&);
        virtual ~Item();

        void setPos(const int&, const int&);
        void draw(sf::RenderWindow&);
    protected:
        sf::Sprite sprite;
        sf::Texture texture;
        int posX, posY;
        Type type;
    private:
};

#endif

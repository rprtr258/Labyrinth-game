#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

class Inventory {
    public:
        static void init();
        static void draw(sf::RenderWindow&);

        static void show();
        static void hide();
        static const bool& visible();
        static void clear();
    private:
        static Item* inv[4][3];
        static bool showed;
        static sf::Texture texture;
        static sf::Sprite sprite;
};

#endif

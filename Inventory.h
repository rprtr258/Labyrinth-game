#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include "Drawer.h"

class Inventory {
    public:
        static void init();
        static void draw(sf::RenderWindow&);
        static const sf::Sprite& getSprite();

        static void show();
        static void hide();
        static const bool& visible();
        static void click();
        static void clear();
    private:
        static Item* inv[4][3];
        static Item* dr;
        static bool showed, drag;
        static int dTargetX, dTargetY;
        static sf::Texture texture;
        static sf::Sprite sprite;
};

#endif

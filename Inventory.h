#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include "DrawableInterface.h"

class Inventory:public DrawableInterface {
    public:
        Inventory();
        ~Inventory();
        void draw(sf::RenderWindow&);

        void show();
        void hide();
    private:
        Item* inv[4][3];
        bool showed;
};

#endif

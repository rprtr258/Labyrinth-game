#include "Inventory.h"

Inventory::Inventory() {
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            inv[i][j] = new Item(i, j);
        }
    }
    showed = false;
}

Inventory::~Inventory() {
    for(int i=0;i<4;i++) for(int j=0;j<3;j++) delete inv[i][j];
}

void Inventory::show() {
    showed = true;
}

void Inventory::hide() {
    showed = false;
}

void Inventory::draw(sf::RenderWindow &window) {
    if(showed) {
        for(int i=0;i<4;i++) {
            for(int j=0;j<3;j++) {
                inv[i][j]->draw(window);
            }
        }
    }
}

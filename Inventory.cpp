#include "Inventory.h"

Item* Inventory::inv[4][3];
bool Inventory::showed;
sf::Texture Inventory::texture;
sf::Sprite Inventory::sprite;

void Inventory::init() {
    texture = TexturesStorage::getTexture("Inventory");
    sprite.setTexture(texture);
    sprite.setPosition(56.0f, 160.0f);
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            inv[i][j] = new Item(i, j);
        }
    }
    showed = false;
}

void Inventory::show() {
    showed = true;
}

void Inventory::hide() {
    showed = false;
}

const bool& Inventory::visible() {
    return showed;
}

void Inventory::clear() {
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            delete inv[i][j];
        }
    }
}

void Inventory::draw(sf::RenderWindow &window) {
    if(showed) {
        window.draw(sprite);
        for(int i=0;i<4;i++) {
            for(int j=0;j<3;j++) {
                inv[i][j]->draw(window);
            }
        }
    }
}

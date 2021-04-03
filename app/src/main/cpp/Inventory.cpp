#include "Inventory.h"
#include <iostream>

Item* Inventory::inv[4][3];
Item* Inventory::dr;
bool Inventory::showed, Inventory::drag;
sf::Texture Inventory::texture;
sf::Sprite Inventory::sprite;
int Inventory::dTargetX, Inventory::dTargetY;

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
    drag = false;
    dTargetX = dTargetY = -1;
}

const sf::Sprite& Inventory::getSprite() {
    return sprite;
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
        if(drag) dr->draw(window);
    }
}

void Inventory::click() {
    if(showed &&
      (sf::Mouse::getPosition(Drawer::getWindow()).x-56-35)%65<54 &&
      (sf::Mouse::getPosition(Drawer::getWindow()).y-160-27)%65<54) {
        int cellx = (sf::Mouse::getPosition(Drawer::getWindow()).x-56-35)/65;
        int celly = (sf::Mouse::getPosition(Drawer::getWindow()).y-160-27)/65;
        std::cout << cellx << ' ' << celly << ' ' << drag << std::endl;
        if(drag) {
            inv[cellx][celly]->setPos(dTargetX, dTargetY);
            inv[dTargetX][dTargetY]->setPos(cellx, celly);
            std::swap(inv[cellx][celly], inv[dTargetX][dTargetY]);
            dTargetX = dTargetY = -1;
            inv[cellx][celly]->unfollowMouse();
            dr = NULL;
            drag = false;
        } else {
            dTargetX = cellx;
            dTargetY = celly;
            inv[cellx][celly]->followMouse();
            dr = inv[cellx][celly];
            drag = true;
        }
    }
}

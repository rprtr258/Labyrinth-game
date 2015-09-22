#include "Item.h"

Item::Item() {
    texture = TexturesStorage::getEmptyCellTexture();
    sprite.setTexture(texture);
    setPos(0, 0);
    type = Empty;
}

Item::Item(const int &posX, const int &posY) {
    texture = TexturesStorage::getEmptyCellTexture();
    sprite.setTexture(texture);
    setPos(posX, posY);
    type = Empty;
}

Item::~Item() {
    ;
}

void Item::setPos(const int &posX, const int &posY) {
    this->posX = posX;
    this->posY = posY;
    sprite.setPosition(504+posX*34, 152+posY*34);
}

void Item::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

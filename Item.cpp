#include "Item.h"

Item::Item() {
    texture = TexturesStorage::getTexture("Empty_Cell");
    sprite.setTexture(texture);
    setPos(0, 0);
    type = Empty;
}

Item::Item(const int &posX, const int &posY) {
    texture = TexturesStorage::getTexture("Empty_Cell");
    sprite.setTexture(texture);
    setPos(posX, posY);
    type = Empty;
}

Item::~Item() {
}

void Item::setPos(const int &posX, const int &posY) {
    this->posX = posX;
    this->posY = posY;
    sprite.setPosition(56+35+posX*65, 160+27+posY*65);
}

void Item::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

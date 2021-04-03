#include "Cell.h"

Cell::Cell() {
}


sf::Sprite &Cell::getSprite() {
    return sprite;
}

void Cell::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Cell::setType(int newType) {
    type = newType;
    texture.loadFromImage(TexturesStorage::getMainTexture(), sf::IntRect((newType%16)*CELL_SIZE,(newType/16)*CELL_SIZE, CELL_SIZE, CELL_SIZE));
    sprite.setTexture(texture);
}

int Cell::getType() {
    return type;
}

bool Cell::getWall(const int &wall) {
    return type & wall;
}

void Cell::addWall(int wall) {
    type = type | wall;
    setType(type);
}

void Cell::removeWall(int wall) {
    type = type & (~wall);
    setType(type);
}

void Cell::addCorner(int corner) {
    type = type | corner;
    setType(type);
}

void Cell::removeCorner(int corner) {
    type = type & (~corner);
    setType(type);
}

#include "Turn.h"

Turn::Turn() {
}

void Turn::set(sf::Keyboard::Key key, int wall, float dirx, float diry) {
    this->key  = key;
    this->wall = wall;
    this->dirx = dirx;
    this->diry = diry;
}

const sf::Keyboard::Key& Turn::getKey() const {
    return key;
}

const int& Turn::getWall() const {
    return wall;
}

const float& Turn::getDirX() const {
    return dirx;
}

const float& Turn::getDirY() const {
    return diry;
}

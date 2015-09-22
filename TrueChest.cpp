#include "TrueChest.h"

TrueChest::TrueChest() {
    visible = false;
    texture = TexturesStorage::getChestTexture();
    sprite.setTexture(texture);
}

const std::pair<int, int>& TrueChest::getCords() {
    return cords;
}

void TrueChest::setCords(std::pair<int, int> cords) {
    this->cords = cords;
    sprite.setPosition(cords.first*CELL_SIZE, cords.second*CELL_SIZE);
}

void TrueChest::setVisible(const bool &val) {
    visible = val;
}

void TrueChest::draw(sf::RenderWindow &window) {
    if(visible) window.draw(sprite);
}

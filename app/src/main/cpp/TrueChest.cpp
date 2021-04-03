#include "TrueChest.h"

sf::Texture TrueChest::texture;
sf::Sprite TrueChest::sprite;
bool TrueChest::visible;
std::pair<int, int> TrueChest::cords;

void TrueChest::init() {
    visible = false;
    texture = TexturesStorage::getTexture("Chest");
    sprite.setTexture(texture);
}

const std::pair<int, int>& TrueChest::getCords() {
    return cords;
}

void TrueChest::setCords(std::pair<int, int> cords) {
    TrueChest::cords = cords;
    sprite.setPosition(cords.first*CELL_SIZE, cords.second*CELL_SIZE);
}

void TrueChest::setVisible(const bool &val) {
    visible = val;
}

void TrueChest::draw(sf::RenderWindow &window) {
    if(visible) window.draw(sprite);
}
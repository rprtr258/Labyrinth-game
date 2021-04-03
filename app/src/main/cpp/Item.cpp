#include "Item.h"

Item::Item() {
    texture = TexturesStorage::getTexture("Empty_Cell");
    sprite.setTexture(texture);
    setPos(0, 0);
    type = Empty;
    follMouse = false;
}

Item::Item(const int &posX, const int &posY) {
    texture = TexturesStorage::getTexture("Empty_Cell");
    std::string mas[12] = {"img\\items\\custom_bow.png",
                           "img\\items\\custom_arrow.png",
                           "img\\items\\flint_and_steel.png",
                           "img\\items\\gold_axe.png",
                           "img\\items\\gold_boots.png",
                           "img\\items\\gold_chestplate.png",
                           "img\\items\\gold_helmet.png",
                           "img\\items\\gold_pants.png",
                           "img\\items\\gold_pickaxe.png",
                           "img\\items\\gold_hoe.png",
                           "img\\items\\gold_spade.png",
                           "img\\items\\gold_sword.png"};
    texture.loadFromFile(mas[rand()%12]);
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
    if(follMouse) {
        sprite.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    }
    window.draw(sprite);
}

void Item::followMouse() {
    follMouse = true;
}

void Item::unfollowMouse() {
    follMouse = false;
}

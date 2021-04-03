#include "Controller.h"

bool Controller::lmbPressed;

bool isClickedOnSprite(const sf::Sprite&, const sf::RenderWindow&);

void Controller::init() {
    lmbPressed = false;
}

void Controller::processKey(const sf::Keyboard::Key& key) {
    if(key==sf::Keyboard::Up || key==sf::Keyboard::Down || key==sf::Keyboard::Right || key==sf::Keyboard::Left) {
        Model::moveHero(key);
    } else
    if(key==sf::Keyboard::E) {
        Model::turnInvShow();
    }
}

void Controller::click() {
    if(isClickedOnSprite(Inventory::getSprite(), Drawer::getWindow()) && !lmbPressed) {
        Inventory::click();
        lmbPressed = true;
    }
}

void Controller::unclickLeft() {
    lmbPressed = false;
}

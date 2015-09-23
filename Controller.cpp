#include "Controller.h"

void Controller::processKey(const sf::Keyboard::Key& key) {
    if(key==sf::Keyboard::Up || key==sf::Keyboard::Down || key==sf::Keyboard::Right || key==sf::Keyboard::Left) {
        Model::moveHero(key);
    } else
    if(key==sf::Keyboard::E) {
        Model::turnInvShow();
    }
}

#include "Controller.h"

Controller::Controller() {
}

Controller::~Controller() {
    //delete model;
}

void Controller::setModel(Model *model) {
    this->model = model;
}

void Controller::processKey(const sf::Keyboard::Key& key) {
    if(key==sf::Keyboard::Up || key==sf::Keyboard::Down || key==sf::Keyboard::Right || key==sf::Keyboard::Left) {
        model->moveHero(key);
    } else if(key==sf::Keyboard::Space) {
        model->turnInvShow();
    }
}

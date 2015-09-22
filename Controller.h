#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SFML/Graphics.hpp>

#include "Model.h"

class Controller {
    public:
        Controller();
        ~Controller();
        void processKey(const sf::Keyboard::Key&);
        void setModel(Model*);
    private:
        Model *model;
};

#endif

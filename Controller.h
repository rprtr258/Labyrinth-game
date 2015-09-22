#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SFML/Graphics.hpp>

#include "Model.h"

class Controller {
    public:
        static void processKey(const sf::Keyboard::Key&);
};

#endif

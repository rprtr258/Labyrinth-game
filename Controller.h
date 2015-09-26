#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SFML/Graphics.hpp>

#include "Model.h"

class Controller {
    public:
        static void init();
        static void processKey(const sf::Keyboard::Key&);
        static void click();
        static void unclickLeft();
    private:
        static bool lmbPressed;
};

#endif

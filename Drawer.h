#ifndef DRAWER_H
#define DRAWER_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "DrawableInterface.h"

class Drawer {
    public:
        Drawer();
        void pushDrawable(DrawableInterface*);
        void setGUI(DrawableInterface*);

        sf::View& getView();
        sf::RenderWindow& getWindow();

        void draw();
    private:
        sf::RenderWindow window;
        sf::View view;
        DrawableInterface *gui;
        std::vector<DrawableInterface*> things;
};

#endif

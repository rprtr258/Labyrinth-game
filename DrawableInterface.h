#ifndef DRAWABLEINTERFACE_H
#define DRAWABLEINTERFACE_H

#include <SFML/Graphics.hpp>

class DrawableInterface {
    public:
        DrawableInterface();
        virtual ~DrawableInterface();
        virtual void draw(sf::RenderWindow&) = 0;
    private:
};

#endif

#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

#include "DrawableInterface.h"
#include "TexturesStorage.h"

class GUI:public DrawableInterface {
    public:
        GUI();
        void draw(sf::RenderWindow&);
        void setHealth(const int&);
    private:
        sf::Sprite mainSprite;
        sf::Texture *mainTexture;
        sf::Texture* healthTextures[5];
        sf::Sprite healthSprites[5];
};

#endif

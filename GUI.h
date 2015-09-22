#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

#include "TexturesStorage.h"

class GUI {
    public:
        static void init();
        static void draw(sf::RenderWindow&);
        static void setHealth(const int&);
    private:
        static sf::Sprite mainSprite;
        static sf::Texture mainTexture;
        static sf::Texture healthTextures[5];
        static sf::Sprite healthSprites[5];
};

#endif

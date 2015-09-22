#ifndef TRUECHEST_H
#define TRUECHEST_H

#include <SFML/Graphics.hpp>

#include "TexturesStorage.h"
#include "Constants.h"
#include "DrawableInterface.h"

class TrueChest:public DrawableInterface {
    public:
        TrueChest();

        const std::pair<int, int>& getCords();
        void setCords(std::pair<int, int>);

        void setVisible(const bool&);

        void draw(sf::RenderWindow &window);
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        bool visible;
        std::pair<int, int> cords;
};

#endif

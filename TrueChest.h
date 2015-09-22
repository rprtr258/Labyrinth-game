#ifndef TRUECHEST_H
#define TRUECHEST_H

#include <SFML/Graphics.hpp>

#include "TexturesStorage.h"
#include "Constants.h"

class TrueChest {
    public:
        static void init();

        static const std::pair<int, int>& getCords();
        static void setCords(std::pair<int, int>);

        static void setVisible(const bool&);

        static void draw(sf::RenderWindow &window);
    private:
        static sf::Texture texture;
        static sf::Sprite sprite;
        static bool visible;
        static std::pair<int, int> cords;
};

#endif

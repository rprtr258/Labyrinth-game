#ifndef MESSAGER_H
#define MESSAGER_H

#include <SFML/Graphics.hpp>

class Messenger {
    public:
        static void init();
        static void draw(sf::RenderWindow&);
        static void putString(const std::string&);
    private:
        static sf::Text messages[5];
        static sf::Font font;
};

#endif

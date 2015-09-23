#include "Messenger.h"

sf::Text Messenger::messages[5];
sf::Font Messenger::font;

void Messenger::init() {
    font.loadFromFile("times.ttf");
    for(int i=0;i<5;i++) {
        messages[i].setString("");
        messages[i].setPosition(10.0f, 750-i*40);
        messages[i].setColor(sf::Color(75, 192, 33));
        messages[i].setFont(font);
    }
}

void Messenger::draw(sf::RenderWindow &window) {
    for(int i=0;i<5;i++) {
        window.draw(messages[i]);
    }
}

void Messenger::putString(const std::string &str) {
    for(int i=4;i>0;i--) {
        messages[i].setString(messages[i-1].getString());
    }
    messages[0].setString(str);
}

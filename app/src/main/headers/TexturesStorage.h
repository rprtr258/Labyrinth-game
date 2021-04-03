#ifndef TEXTURESSTORAGE_H
#define TEXTURESSTORAGE_H

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

class TexturesStorage {
    public:
        static void loadTexture(const std::string&, const std::string&);
        static sf::Texture& getTexture(const std::string&);

        static void loadMainTexture(const std::string&);
        static sf::Image& getMainTexture();
    private:
        TexturesStorage();
        static sf::Image mainTexture;
        static std::vector<std::pair<std::string, sf::Texture> > array;
};

#endif

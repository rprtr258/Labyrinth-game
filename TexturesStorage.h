#ifndef TEXTURESSTORAGE_H
#define TEXTURESSTORAGE_H

#include <string>

#include <SFML/Graphics.hpp>

class TexturesStorage {
    public:
        static void loadHeartsTexture(const std::string&, const std::string&, const std::string&);
        static sf::Texture& getHeartTexture(const int&);

        static void loadMainTexture(const std::string&);
        static sf::Image& getMainTexture();

        static void loadPlayerTexture(const std::string&);
        static sf::Texture& getPlayerTexture();

        static void loadChestTexture(const std::string&);
        static sf::Texture& getChestTexture();

        static void loadGuiTexture(const std::string&);
        static sf::Texture& getGuiTexture();

        static void loadEmptyCellTexture(const std::string&);
        static sf::Texture& getEmptyCellTexture();
    private:
        TexturesStorage();
        static sf::Image mainTexture;
        static sf::Texture playerTexture, chestTexture, guiTexture;
        static sf::Texture hearts[3];
        static sf::Texture emptyCell;
};

#endif

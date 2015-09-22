#include "TexturesStorage.h"

sf::Image TexturesStorage::mainTexture;
sf::Texture TexturesStorage::hearts[3];
sf::Texture TexturesStorage::playerTexture, TexturesStorage::chestTexture, TexturesStorage::guiTexture;
sf::Texture TexturesStorage::emptyCell;

TexturesStorage::TexturesStorage() {}

void TexturesStorage::loadHeartsTexture(const std::string &path1, const std::string &path2, const std::string &path3) {
    hearts[0].loadFromFile(path1);
    hearts[1].loadFromFile(path2);
    hearts[2].loadFromFile(path3);
}

sf::Texture& TexturesStorage::getHeartTexture(const int &num) {
    return hearts[num];
}

void TexturesStorage::loadMainTexture(const std::string &path) {
    mainTexture.loadFromFile(path);
}

sf::Image& TexturesStorage::getMainTexture() {
    return mainTexture;
}

void TexturesStorage::loadPlayerTexture(const std::string &path) {
    playerTexture.loadFromFile(path);
}

sf::Texture& TexturesStorage::getPlayerTexture() {
    return playerTexture;
}

void TexturesStorage::loadChestTexture(const std::string &path) {
    chestTexture.loadFromFile(path);
}

sf::Texture& TexturesStorage::getChestTexture() {
    return chestTexture;
}

void TexturesStorage::loadGuiTexture(const std::string &path) {
    guiTexture.loadFromFile(path);
}

sf::Texture& TexturesStorage::getGuiTexture() {
    return guiTexture;
}

void TexturesStorage::loadEmptyCellTexture(const std::string &path) {
    emptyCell.loadFromFile(path);
}

sf::Texture& TexturesStorage::getEmptyCellTexture() {
    return emptyCell;
}

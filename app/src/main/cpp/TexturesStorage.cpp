#include "TexturesStorage.h"

std::vector<std::pair<std::string, sf::Texture> > TexturesStorage::array;
sf::Image TexturesStorage::mainTexture;

void TexturesStorage::loadTexture(const std::string &name, const std::string &path) {
    sf::Texture texture;
    texture.loadFromFile(path);
    array.push_back(std::make_pair(name, texture));
}

sf::Texture& TexturesStorage::getTexture(const std::string &name) {
    for(std::vector<std::pair<std::string, sf::Texture> >::iterator i = array.begin(); i!=array.end();i++) {
        if(i->first==name) return i->second;
    }
    return array.at(0).second;
}

void TexturesStorage::loadMainTexture(const std::string &path) {
    mainTexture.loadFromFile(path);
}

sf::Image& TexturesStorage::getMainTexture() {
    return mainTexture;
}

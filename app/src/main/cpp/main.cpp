#include <SFML/Graphics.hpp>

#include "Drawer.h"
#include "Controller.h"
#include "Model.h"

#include "TexturesStorage.h"

bool testChance(int chance) {
    return (rand()%100)<chance;
}

bool isClickedOnRectangle(const int x1, const int y1, const int x2, const int y2, const sf::Window &window) {
    sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
    if (mouseCoords.x<=x2 && mouseCoords.x>=x1 &&
        mouseCoords.y<=y2 && mouseCoords.y>=y1) {
        return true;
    }
    return false;
}

bool isClickedOnSprite(const sf::Sprite &sprite, const sf::RenderWindow &window) {
    const sf::Vector2f &spriteCoords = sprite.getPosition();
    const sf::Vector2u  &textureSize = sprite.getTexture()->getSize();
    if(isClickedOnRectangle(spriteCoords.x,spriteCoords.y,spriteCoords.x+textureSize.x,spriteCoords.y+textureSize.y,window)) {
        return true;
    }
    return false;
}

int main() {
    srand(time(NULL));
    TexturesStorage::loadMainTexture("img\\sprites_pack_3.png");
    TexturesStorage::loadTexture("Player", "img\\player.png");
    TexturesStorage::loadTexture("Chest", "img\\chest.png");
    TexturesStorage::loadTexture("GUI", "img\\gui.png");
    TexturesStorage::loadTexture("Full_Heart", "img\\heart_full.png");
    TexturesStorage::loadTexture("Half_Full_Heart", "img\\heart_half_full.png");
    TexturesStorage::loadTexture("Empty_Heart", "img\\heart_empty.png");
    TexturesStorage::loadTexture("Empty_Cell", "img\\empty_cell.png");
    TexturesStorage::loadTexture("Inventory", "img\\inventory.png");
    TexturesStorage::loadTexture("Exit_Cell", "img\\exit.png");

    Model::init();
    Drawer::init();
    Controller::init();

    while (Drawer::getWindow().isOpen()) {
        sf::Event event;
        while(Drawer::getWindow().pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                Drawer::getWindow().close();
            if(event.type == sf::Event::KeyPressed) {
                Controller::processKey(event.key.code);
            }
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                Controller::click();
            }
            if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                Controller::unclickLeft();
            }
        }
        Drawer::getWindow().clear();
        Drawer::draw();
        Model::animationStep();
        Drawer::getWindow().display();
    }
    Labyrinth::clear();
    Inventory::clear();
    return 0;
}

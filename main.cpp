#include <SFML/Graphics.hpp>

#include "Drawer.h"
#include "Controller.h"
#include "Model.h"

#include "TexturesStorage.h"

bool testChance(int chance) {
    return (rand()%100)<chance;
}

void clearMemory() {
    Labyrinth::clear();
    Inventory::clear();
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

    Model::init();
    Drawer::init();

    while (Drawer::getWindow().isOpen()) {
        sf::Event event;
        while(Drawer::getWindow().pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                Drawer::getWindow().close();
            if(event.type == sf::Event::KeyPressed) {
                Controller::processKey(event.key.code);
            }
        }
        Drawer::getWindow().clear();
        Drawer::draw();
        Model::animationStep();
        Drawer::getWindow().display();
    }
    clearMemory();
    return 0;
}

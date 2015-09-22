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
    TexturesStorage::loadPlayerTexture("img\\player.png");
    TexturesStorage::loadChestTexture("img\\chest.png");
    TexturesStorage::loadGuiTexture("img\\gui.png");
    TexturesStorage::loadHeartsTexture("img\\heart_full.png", "img\\heart_half_full.png", "img\\heart_empty.png");
    TexturesStorage::loadEmptyCellTexture("img\\empty_cell.png");

    Drawer::init();
    Model::init();

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

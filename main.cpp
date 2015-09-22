#include <SFML/Graphics.hpp>

#include "Drawer.h"
#include "Controller.h"
#include "Model.h"

#include "TexturesStorage.h"

bool testChance(int chance) {
    return (rand()%100)<chance;
}

int main() {
    srand(time(NULL));
    TexturesStorage::loadMainTexture("img\\sprites_pack_3.png");
    TexturesStorage::loadPlayerTexture("img\\player.png");
    TexturesStorage::loadChestTexture("img\\chest.png");
    TexturesStorage::loadGuiTexture("img\\gui.png");
    TexturesStorage::loadHeartsTexture("img\\heart_full.png", "img\\heart_half_full.png", "img\\heart_empty.png");
    TexturesStorage::loadEmptyCellTexture("img\\empty_cell.png");

    Controller controller;
    Drawer drawer;
    Model model;

    model.setDrawer(&drawer);
    controller.setModel(&model);
    model.setView();
    while (drawer.getWindow().isOpen()) {
        sf::Event event;
        while(drawer.getWindow().pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                drawer.getWindow().close();
            if(event.type == sf::Event::KeyPressed) {
                controller.processKey(event.key.code);
            }
        }
        drawer.getWindow().clear();
        drawer.draw();
        model.animationStep();
        drawer.getWindow().display();
    }
    return 0;
}

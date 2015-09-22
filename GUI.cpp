#include "GUI.h"

GUI::GUI() {
    mainTexture = &TexturesStorage::getGuiTexture();
    mainSprite.setPosition(0.0f, 0.0f);
    mainSprite.setTexture(*mainTexture);
    for(int i=0;i<5;i++) {
        healthTextures[i] = &TexturesStorage::getHeartTexture(0);
        healthSprites[i].setTexture(*healthTextures[i]);
        healthSprites[i].setPosition(123.0f + 23.0f*i, 18.0f);
    }
}

void GUI::setHealth(const int &health) {
    int i;
    for(i=0;i<health/2;i++) {
        healthTextures[i] = &TexturesStorage::getHeartTexture(0);
        healthSprites[i].setTexture(*healthTextures[i]);
    }
    if(health%2==1) {
        healthTextures[i] = &TexturesStorage::getHeartTexture(1);
        healthSprites[i].setTexture(*healthTextures[i]);
        i++;
    }
    for(;i<5;i++) {
        healthTextures[i] = &TexturesStorage::getHeartTexture(2);
        healthSprites[i].setTexture(*healthTextures[i]);
    }
}

void GUI::draw(sf::RenderWindow &window) {
    window.draw(mainSprite);
    for(int i=0;i<5;i++) {
        window.draw(healthSprites[i]);
    }
}

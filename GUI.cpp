#include "GUI.h"

sf::Sprite GUI::mainSprite;
sf::Texture GUI::mainTexture;
sf::Texture GUI::healthTextures[5];
sf::Sprite GUI::healthSprites[5];

void GUI::init() {
    mainTexture = TexturesStorage::getGuiTexture();
    mainSprite.setPosition(0.0f, 0.0f);
    mainSprite.setTexture(mainTexture);
    for(int i=0;i<5;i++) {
        healthTextures[i] = TexturesStorage::getHeartTexture(0);
        healthSprites[i].setTexture(healthTextures[i]);
        healthSprites[i].setPosition(123.0f + 23.0f*i, 18.0f);
    }
}

void GUI::setHealth(const int &health) {
    int i;
    for(i=0;i<health/2;i++) healthTextures[i] = TexturesStorage::getHeartTexture(0);
    if(health%2==1) {
        healthTextures[i] = TexturesStorage::getHeartTexture(1);
        i++;
    }
    for(;i<5;i++) healthTextures[i] = TexturesStorage::getHeartTexture(2);

    for(int i=0;i<5;i++) healthSprites[i].setTexture(healthTextures[i]);
}

void GUI::draw(sf::RenderWindow &window) {
    window.draw(mainSprite);
    for(int i=0;i<5;i++) {
        window.draw(healthSprites[i]);
    }
}

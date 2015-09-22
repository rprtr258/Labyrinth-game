#include "Player.h"

Player::Player() {
    texture = TexturesStorage::getPlayerTexture();
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    x = 0;
    y = 0;
}

Player::Player(float x, float y) {
    texture = TexturesStorage::getPlayerTexture();
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    x = 0;
    y = 0;
}

void Player::move(float x, float y) {
    sprite.setPosition(sprite.getPosition().x + x, sprite.getPosition().y + y);
}

void Player::move(int dx, int dy) {
    stats.move(dx, dy);
}

std::pair<int, int> Player::getPos() {
    return stats.getCords();
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

PlayerStats& Player::getStats() {
    return stats;
}

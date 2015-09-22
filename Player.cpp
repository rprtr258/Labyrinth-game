#include "Player.h"

sf::Texture Player::texture;
sf::Sprite Player::sprite;
int Player::x, Player::y;
PlayerStats Player::stats;
Player::MoveDir Player::dir;

void Player::init() {
    texture = TexturesStorage::getPlayerTexture();
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
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

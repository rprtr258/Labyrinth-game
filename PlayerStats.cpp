#include "PlayerStats.h"

PlayerStats::PlayerStats() {
    cordX = cordY = 0;
    health = 10;
}

void PlayerStats::move(const int &dX, const int &dY) {
    cordX+=dX;
    cordY+=dY;
}

std::pair<int, int> PlayerStats::getCords() const {
    return std::make_pair(cordX, cordY);
}

void PlayerStats::damage(const int &dmg) {
    health-=dmg;
}

void PlayerStats::heal(const int &heal) {
    health = std::min(10, health + heal);
}

const int& PlayerStats::getHealth() const {
    return health;
}

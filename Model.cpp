#include "Model.h"

Turn Model::moves[4];
float Model::dirx, Model::diry, Model::speed;
bool Model::playerMoves;

void Model::init() {
    TrueChest::init();
    Inventory::init();
    Labyrinth::init();
    Labyrinth::generate();
    GUI::init();
    int chestX = WIDTH-10, chestY = HEIGHT-10;
    speed = 0.8f;
    while(Labyrinth::array[chestX][chestY]->getWall(Cell::RIGHT) +
          Labyrinth::array[chestX][chestY]->getWall(Cell::LEFT) +
          Labyrinth::array[chestX][chestY]->getWall(Cell::UP) +
          Labyrinth::array[chestX][chestY]->getWall(Cell::DOWN)!=3) {
        chestX = rand()%WIDTH;
        chestY = rand()%HEIGHT;
    }
    TrueChest::setCords(std::make_pair(chestX, chestY));
    Player::init();
    GUI::setHealth(Player::getStats().getHealth());
    moves[0].set(sf::Keyboard::Up,    Cell::UP,    0.0f, -speed);
    moves[1].set(sf::Keyboard::Right, Cell::RIGHT, speed,  0.0f);
    moves[2].set(sf::Keyboard::Down,  Cell::DOWN,  0.0f,  speed);
    moves[3].set(sf::Keyboard::Left,  Cell::LEFT, -speed,  0.0f);
}

void Model::moveHero(const sf::Keyboard::Key& key) {
    for(int i=0;i<4;i++) {
        if(key==moves[i].getKey() &&
           !Labyrinth::array[Player::getPos().first][Player::getPos().second]->getWall(moves[i].getWall()) &&
           !playerMoves) {
            Player::move(int(moves[i].getDirX()*1/speed), int(moves[i].getDirY()*1/speed));
            setAnimDir(moves[i].getDirX(), moves[i].getDirY());
            setPlayerMoves(true);
            setView();
        }
    }
}

void Model::turnInvShow() {
    if(Inventory::visible())
        Inventory::hide();
    else
        Inventory::show();
}

const bool& Model::getPlayerMoves() {
    return playerMoves;
}

void Model::setPlayerMoves(const bool& state) {
    playerMoves = state;
}

bool Model::isVisibleCell(const int &x, const int &y) {
    int px = Player::getPos().first, py = Player::getPos().second;
    if(x==px && y==py) return true;
    if(px<WIDTH-1 && x==px+1 && y==py && !Labyrinth::array[px][py]->getWall(Cell::RIGHT)) {
        return true;
    }
    if(px>0 && x==px-1 && y==py && !Labyrinth::array[px][py]->getWall(Cell::LEFT)) {
        return true;
    }
    if(py>0 && x==px && y==py-1 && !Labyrinth::array[px][py]->getWall(Cell::UP)) {
        return true;
    }
    if(py<HEIGHT-1 && x==px && y==py+1 && !Labyrinth::array[px][py]->getWall(Cell::DOWN)) {
        return true;
    }
    return false;
}

void Model::animationStep() {
    static int playerSteps = 0;
    if(!playerMoves) return;
    playerSteps++;
    Drawer::getView().move(dirx, diry);
    Player::move(dirx, diry);
    if(playerSteps==ceilf(128.0f/speed)) {
        playerMoves = false;
        playerSteps = 0;
    }
}

void Model::setView() {
    for(int i=0;i<WIDTH;i++) {
        for(int j=0;j<HEIGHT;j++) {
            Labyrinth::setDrawableCell(i, j, isVisibleCell(i, j));
        }
    }
    const std::pair<int, int> &chestCords = TrueChest::getCords();
    TrueChest::setVisible(isVisibleCell(chestCords.first, chestCords.second));
}

void Model::setAnimDir(const float& dx, const float& dy) {
    dirx = dx;
    diry = dy;
}

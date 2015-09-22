#include "Model.h"

Model::Model() {
    trueChest = new TrueChest();
    inventory = new Inventory();
    lab = new Labyrinth();
    lab->generate();
    gui = new GUI();
    int chestX = WIDTH-10, chestY = HEIGHT-10;
    speed = 0.8f;
    while(lab->array[chestX][chestY]->getWall(Cell::RIGHT) +
          lab->array[chestX][chestY]->getWall(Cell::LEFT) +
          lab->array[chestX][chestY]->getWall(Cell::UP) +
          lab->array[chestX][chestY]->getWall(Cell::DOWN)!=3) {
        chestX = rand()%WIDTH;
        chestY = rand()%HEIGHT;
    }
    trueChest->setCords(std::make_pair(chestX, chestY));
    player = new Player(lab->array[0][0]->getSprite().getPosition().x, lab->array[0][0]->getSprite().getPosition().y);
    //gui->setHealth(player->getStats().getHealth());
    gui->setHealth(3);
    moves[0].set(sf::Keyboard::Up,    Cell::UP,    0.0f, -speed);
    moves[1].set(sf::Keyboard::Right, Cell::RIGHT, speed,  0.0f);
    moves[2].set(sf::Keyboard::Down,  Cell::DOWN,  0.0f,  speed);
    moves[3].set(sf::Keyboard::Left,  Cell::LEFT, -speed,  0.0f);
}

Model::~Model() {
    delete lab;
    delete player;
    delete trueChest;
    delete gui;
    delete inventory;
}

Labyrinth* Model::getLabyrinth() {
    return lab;
}

Player* Model::getPlayer() {
    return player;
}

void Model::moveHero(const sf::Keyboard::Key& key) {
    for(int i=0;i<4;i++) {
        if(key==moves[i].getKey() &&
           !lab->array[player->getPos().first][player->getPos().second]->getWall(moves[i].getWall()) &&
           !playerMoves) {
            //player->move(dx, dy);
            player->move(int(moves[i].getDirX()*1/speed), int(moves[i].getDirY()*1/speed));
            setAnimDir(moves[i].getDirX(), moves[i].getDirY());
            //drawer->getView().move(moves[i].getDirX()*1280, moves[i].getDirY()*1280);
            setPlayerMoves(true);
            setView();
        }
    }
}

void Model::turnInvShow() {
    static bool invShowed = false;
    if(invShowed) {
        inventory->hide();
        invShowed = false;
    } else {
        inventory->show();
        invShowed = true;
    }
}

void Model::setDrawer(Drawer* drawer) {
    this->drawer = drawer;
    drawer->setGUI(gui);
    drawer->pushDrawable(lab);
    drawer->pushDrawable(trueChest);
    drawer->pushDrawable(player);
    drawer->pushDrawable(inventory);
}

const bool& Model::getPlayerMoves() {
    return playerMoves;
}

void Model::setPlayerMoves(const bool& state) {
    playerMoves = state;
}

bool Model::isVisibleCell(const int &x, const int &y) {
    int px = player->getPos().first, py = player->getPos().second;
    if(x==px && y==py) return true;
    if(px<WIDTH-1 && x==px+1 && y==py && !lab->array[px][py]->getWall(Cell::RIGHT)) {
        return true;
    }
    if(px>0 && x==px-1 && y==py && !lab->array[px][py]->getWall(Cell::LEFT)) {
        return true;
    }
    if(py>0 && x==px && y==py-1 && !lab->array[px][py]->getWall(Cell::UP)) {
        return true;
    }
    if(py<HEIGHT-1 && x==px && y==py+1 && !lab->array[px][py]->getWall(Cell::DOWN)) {
        return true;
    }
    return false;
}

void Model::animationStep() {
    static int playerSteps = 0;
    if(!playerMoves) return;
    playerSteps++;
    drawer->getView().move(dirx, diry);
    player->move(dirx, diry);
    if(playerSteps==ceilf(128.0f/speed)) {
        playerMoves = false;
        playerSteps = 0;
    }
}

void Model::setView() {
    for(int i=0;i<WIDTH;i++) {
        for(int j=0;j<HEIGHT;j++) {
            lab->setDrawableCell(i, j, isVisibleCell(i, j));
        }
    }
    const std::pair<int, int> &chestCords = trueChest->getCords();
    trueChest->setVisible(isVisibleCell(chestCords.first, chestCords.second));
}

void Model::setAnimDir(const float& dirx, const float& diry) {
    this->dirx = dirx;
    this->diry = diry;
}

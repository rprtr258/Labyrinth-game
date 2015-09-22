#ifndef MODEL_H
#define MODEL_H

#include <cmath>

#include "Labyrinth.h"
#include "Player.h"
#include "TrueChest.h"
#include "Turn.h"
#include "Drawer.h"
#include "GUI.h"
#include "Inventory.h"

class Model {
    public:
        Model();
        ~Model();
        void moveHero(const sf::Keyboard::Key&);

        Labyrinth* getLabyrinth();
        Player* getPlayer();

        void setDrawer(Drawer*);

        void setPlayerMoves(const bool&);
        const bool& getPlayerMoves();

        void animationStep();
        void setView();
        void turnInvShow();

        void setAnimDir(const float&, const float&);

        bool isVisibleCell(const int&, const int&);
    private:
        Inventory *inventory;
        Labyrinth *lab;
        Player *player;
        Drawer *drawer;
        TrueChest *trueChest;
        Turn moves[4];
        float dirx, diry, speed;
        bool playerMoves;
        GUI *gui;
};

#endif

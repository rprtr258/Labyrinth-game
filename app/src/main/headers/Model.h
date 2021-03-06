#ifndef MODEL_H
#define MODEL_H

#include <cmath>
#include <string>

#include "Labyrinth.h"
#include "Player.h"
#include "TrueChest.h"
#include "Turn.h"
#include "Drawer.h"
#include "GUI.h"
#include "Inventory.h"

class Model {
    public:
        static void init();
        static void moveHero(const sf::Keyboard::Key&);

        static void setPlayerMoves(const bool&);
        static const bool& getPlayerMoves();

        static void animationStep();
        static void setView();
        static void turnInvShow();

        static void setAnimDir(const float&, const float&);

        static bool isVisibleCell(const int&, const int&);
    private:
        static Turn moves[4];
        static float dirx, diry, speed;
        static bool playerMoves;
};

#endif

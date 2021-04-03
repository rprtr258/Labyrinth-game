#ifndef DRAWER_H
#define DRAWER_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "GUI.h"
#include "Labyrinth.h"
#include "Player.h"
#include "TrueChest.h"
#include "Inventory.h"
#include "Messenger.h"

class Drawer {
    public:
        static void init();

        static sf::View& getView();
        static sf::RenderWindow& getWindow();

        static void draw();
    private:
        static sf::RenderWindow window;
        static sf::View view, guiView;
};

#endif

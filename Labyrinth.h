#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Util.h"
#include "DSU.h"
#include "Constants.h"
#include "DrawableInterface.h"

bool testChance(int chance);

class Labyrinth:public DrawableInterface {
    public:
        Labyrinth();
        ~Labyrinth();

        void generate();

        void setDrawableCell(const int&, const int&, const bool&);

        void draw(sf::RenderWindow &window);

        Cell *array[WIDTH][HEIGHT];
        bool drawing[WIDTH][HEIGHT];
};

#endif

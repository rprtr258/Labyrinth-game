#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Util.h"
#include "DSU.h"
#include "Constants.h"

bool testChance(int chance);

class Labyrinth {
    public:
        static void init();

        static void generate();

        static void setDrawableCell(const int&, const int&, const bool&);

        static void draw(sf::RenderWindow &window);

        static void clear();

        static Cell *array[WIDTH][HEIGHT];
        static bool drawing[WIDTH][HEIGHT];
};

#endif

#include "Labyrinth.h"

Cell *Labyrinth::array[WIDTH][HEIGHT];
bool Labyrinth::drawing[WIDTH][HEIGHT];
const int Cell::LEFT, Cell::DOWN, Cell::RIGHT, Cell::UP;
const int Cell::RU_CORNER, Cell::RD_CORNER, Cell::LD_CORNER, Cell::LU_CORNER;

void Labyrinth::init() {
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            array[j][i] = new Cell();
            array[j][i]->getSprite().setPosition(j*CELL_SIZE,i*CELL_SIZE);
            drawing[j][i] = false;
        }
    }
    array[0][0]->setType(9);
    array[WIDTH-1][0]->setType(12);
    array[0][HEIGHT-1]->setType(3);
    array[WIDTH-1][HEIGHT-1]->setType(6);
    for(int i=1;i<WIDTH-1;i++) {
        array[i][0]->setType(8);
        array[i][HEIGHT-1]->setType(2);
    }
    for(int i=1;i<HEIGHT-1;i++) {
        array[0][i]->setType(1);
        array[WIDTH-1][i]->setType(4);
    }
    for(int i=1;i<HEIGHT-1;i++) {
        for(int j=1;j<WIDTH-1;j++) {
            array[j][i]->setType(0);
        }
    }
}

void Labyrinth::clear() {
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            delete array[j][i];
        }
    }
}

void Labyrinth::setDrawableCell(const int &x, const int &y, const bool &val) {
    drawing[x][y] = val;
}

void Labyrinth::draw(sf::RenderWindow &window) {
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            if(drawing[j][i]) {
                array[j][i]->draw(window);
            }
        }
    }
}

void Labyrinth::generate() {
    DSU set(WIDTH);

    int uniqSet=WIDTH+1;

    for(int i=0;i<WIDTH-1;i++) {
        if(rand()%2==1) {
            array[i][0]->addWall(Cell::RIGHT);
            array[i+1][0]->addWall(Cell::LEFT);
        } else {
            set.unite(i, i+1);
        }
    } //установка вертикальных стен в первом ряду
    for(int i=0;i<WIDTH;i++) {
        int start = i;
        int end = i;
        bool emptyIs=false;
        while(end<WIDTH && set.inOneSet(start, end)) end++;
        for(int j=start;j<end;j++) {
            if(rand()%2==1) {
                array[j][0]->addWall(Cell::DOWN);
                array[j][1]->addWall(Cell::UP);
            } else {
                emptyIs = true;
            }
        }
        if(!emptyIs) {
            int r = rand()%(end-start)+start;
            array[r][0]->removeWall(Cell::DOWN);
            array[r][1]->removeWall(Cell::UP);
        }
        i=end;
    } //установка нижних стен в первом ряду
    for(int i=1;i<HEIGHT-1;i++) {
        for(int j=0;j<WIDTH;j++) {
            if(array[j][i-1]->getWall(Cell::DOWN)) {
                set[j] = uniqSet;
                uniqSet++;
                array[j][i]->addWall(Cell::UP);
            } else array[j][i]->removeWall(Cell::UP);
            array[j][i]->removeWall(Cell::DOWN);
        }
        for(int j=0;j<WIDTH-1;j++) {
            if(set.inOneSet(j, j+1)) {
                array[j][i]->addWall(Cell::RIGHT);
                array[j+1][i]->addWall(Cell::LEFT);
            } else {
                if(testChance(50)) {
                    array[j][i]->addWall(Cell::RIGHT);
                    array[j+1][i]->addWall(Cell::LEFT);
                } else {
                    set.unite(j, j+1);
                }
            }
        }
        for(int j=0;j<WIDTH;j++) {
            int start = j;
            int end = j+1;
            bool emptyIs=false;
            while(end<WIDTH && set.inOneSet(start, end)) end++;
            for(int k=start;k<end;k++) {
                if(rand()%2==1) {
                    array[k][i]->addWall(Cell::DOWN);
                    array[k][i+1]->addWall(Cell::UP);
                } else {
                    emptyIs = true;
                }
            }
            if(!emptyIs) {
                int r = rand()%(end-start)+start;
                array[r][i]->removeWall(Cell::DOWN);
                array[r][i+1]->removeWall(Cell::UP);
            }
            j=end;
        }
    } //генерация всех рядов с второго до предпоследнего
    for(int j=0;j<WIDTH;j++) {
        if(array[j][HEIGHT-2]->getWall(Cell::DOWN)) {
            set[j] = uniqSet;
            uniqSet++;
            array[j][HEIGHT-1]->addWall(Cell::UP);
        } else {
            array[j][HEIGHT-1]->removeWall(Cell::UP);
        }
    }
    for(int i=0;i<WIDTH-1;i++) {
        if(set.inOneSet(i, i+1)) {
            array[i][HEIGHT-1]->addWall(Cell::RIGHT);
            array[i+1][HEIGHT-1]->addWall(Cell::LEFT);
        } else {
            array[i][HEIGHT-1]->removeWall(Cell::RIGHT);
            array[i+1][HEIGHT-1]->removeWall(Cell::LEFT);
            set.unite(i, i+1);
        }
    } //генерация последней строки
    int corners[4][7] = {{Cell::RIGHT, Cell::UP,   0, -1,  1, 0, Cell::RU_CORNER},
                         {Cell::RIGHT, Cell::DOWN, 0,  1,  1, 0, Cell::RD_CORNER},
                         {Cell::LEFT,  Cell::UP,   0, -1, -1, 0, Cell::LU_CORNER},
                         {Cell::LEFT,  Cell::DOWN, 0,  1, -1, 0, Cell::LD_CORNER}};
    for(int i=0;i<WIDTH;i++) {
        for(int j=0;j<HEIGHT;j++) {
            for(int k=0;k<4;k++) {
                if((i+corners[k][2]>=0 && i+corners[k][2]<WIDTH && j+corners[k][3]>=0 && j+corners[k][3]<HEIGHT && array[i+corners[k][2]][j+corners[k][3]]->getWall(corners[k][0])) ||
                   (i+corners[k][4]>=0 && i+corners[k][4]<WIDTH && j+corners[k][5]>=0 && j+corners[k][5]<HEIGHT && array[i+corners[k][4]][j+corners[k][5]]->getWall(corners[k][1]))) {
                    array[i][j]->addCorner(corners[k][6]);
                }
            }
        }
    }
    /*int row = rand()%4;
    if(row==0) {
        int pos = rand()%(WIDTH-1)+1;
        array[pos][0]->removeWall(Cell::UP);
        array[pos][0]->addCorner(Cell::RU_CORNER);
        array[pos][0]->addCorner(Cell::LU_CORNER);
    }
    if(row==1) {
        int pos = rand()%(WIDTH-1)+1;
        array[pos][HEIGHT-1]->removeWall(Cell::DOWN);
        array[pos][HEIGHT-1]->addCorner(Cell::RD_CORNER);
        array[pos][HEIGHT-1]->addCorner(Cell::LD_CORNER);
    }
    if(row==2) {
        int pos = rand()%(HEIGHT-1)+1;
        array[0][pos]->removeWall(Cell::LEFT);
        array[0][pos]->addCorner(Cell::LU_CORNER);
        array[0][pos]->addCorner(Cell::LD_CORNER);
    }
    if(row==3) {
        int pos = rand()%HEIGHT;
        array[WIDTH-1][pos]->removeWall(Cell::RIGHT);
        array[WIDTH-1][pos]->addCorner(Cell::RU_CORNER);
        array[WIDTH-1][pos]->addCorner(Cell::RD_CORNER);
    }*/
}

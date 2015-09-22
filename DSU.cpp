#include "DSU.h"

DSU::DSU(int size) {
    mas = new int[size];
    this->size = size;
    for(int i=0;i<size;i++) {
        mas[i] = i+1;
    }
}

DSU::~DSU() {
    delete[] mas;
}

bool DSU::inOneSet(int one, int two) {
    return mas[one] == mas[two];
}

void DSU::unite(int one, int two) {
    int curSet = mas[one], curSet2 = mas[two];
    for(int i=0;i<size;i++) {
        if(mas[i]==curSet2) mas[i] = curSet;
    }
}

int& DSU::operator[](int k) {
    return mas[k];
}

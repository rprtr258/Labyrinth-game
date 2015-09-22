#ifndef DSU_H
#define DSU_H


class DSU {
    public:
        DSU(int size);
        ~DSU();
        bool inOneSet(int, int);
        void unite(int, int);
        int& operator[](int k);
    private:
        int *mas;
        int size;
};

#endif

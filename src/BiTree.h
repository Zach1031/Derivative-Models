#ifndef BITREE
#define BITREE

class BiTree {
    public:
        float sVal; // stock value
        float cVal; // option value at that time
        BiTree *up;
        BiTree *down;

        static void printTree(BiTree *root, int space);

};

#endif
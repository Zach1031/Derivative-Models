#ifndef BITREE
#define BITREE

class BiTree {
    public:
        float val;
        BiTree *up;
        BiTree *down;

        static void printTree(BiTree *root, int space);

};

#endif
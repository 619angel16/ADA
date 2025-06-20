#ifndef BIN3_H
#define BIN3_H
#include "Node.h"
#include <iostream>
using namespace std;

class bin3
{
    Node* root;
    bin3* lft;
    bin3* rgt;

public:
    bin3();

    bin3(int value);

    bin3(Node* node);

    Node* getroot();

    int getHeight();

    int _getHeight(bin3* sub3);

    void printLevel(int level);

    void _printLevel(bin3* sub3, int level);

    bool search(int value);

    bool _search(bin3* sub3, int value);

    void insertNode(Node* newNode);

    void _insertNode(bin3* sub3, Node* newNode);

    /**
     *
     * @param choice preOrden = 0, InOrden = 1, postOrden = 2, Anchura = 3
     */
    void printOrden(int choice);

    void _printOrden(bin3* sub3, int choice);
};

#endif //BIN3_H

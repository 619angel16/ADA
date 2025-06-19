#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node {
private:
    static int id_counter;
    int value;
    int id;

public:
    Node(int value);

    Node();

    void setValue(int value);

    int getValue();

    int getId();
};

#endif //NODE_H

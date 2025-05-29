#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node {
    int value;
    string name;

public:
    Node(string name, int value);

    Node(string name);

    void setValue(int value);

    void setName(string name);

    int getValue();

    string getName();
};

#endif //NODE_H

//
// Created by USER on 28/05/2025.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <map>

#include "Node.h"


class Graph {
    map<string, Node *> nodes;
    list<pair<string, string> > adj;

public:
    Graph(list<Node *> nodeList);

    Graph(list<Node *> nodeList, list<pair<string, string> > matrixAdj);

    list<pair<string, string> > getAdjMatrix();

    map<string, Node *> getNodes();

    void insertNode(Node *newNode);

    void insertEdge(string node1, string node2);

    void printAll();
};

#endif //GRAPH_H

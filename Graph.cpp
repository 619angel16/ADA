//
// Created by USER on 28/05/2025.
//

#include "Graph.h"

#include <iostream>
#include <ostream>

Graph::Graph(list<Node *> nodeList) {
    for (auto it: nodeList) {
        nodes[it->getName()] = it;
    }
}

Graph::Graph(list<Node *> nodeList, list<pair<string, string> > matrixAdj) {
    for (auto it: nodeList) {
        nodes[it->getName()] = it;
    }
    adj = matrixAdj;
}

list<pair<string, string> > Graph::getAdjMatrix() {
    return this->adj;
}

map<string, Node *> Graph::getNodes() {
    return this->nodes;
}

void Graph::insertNode(Node *newNode) {
    this->nodes[newNode->getName()] = newNode;
}

void Graph::insertEdge(string node1, string node2) {
    this->adj.emplace_back(node1, node2);
}

void Graph::printAll() {
    for (auto it: this->getNodes()) {
        cout << "Node: " << it.first << " " << it.second->getValue() << endl;
    }
    for (auto it: this->getAdjMatrix()) {
        cout << "AdjMatrix: " << it.first << " " << it.second << endl;
    }
}

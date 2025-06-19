//
// Created by USER on 28/05/2025.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include "Node.h"

struct Edge
{
    Node* src;
    Node* dst;
    int cost;
};

class Graph
{
    Node* vtx[10]{};
    Edge* edges[45]{};
    bool matrixA[10][10] = {};

public:
    Graph();

    Graph(Node* newNode);

    Graph(list<Node*> listNode);

    bool isEmpty();

    bool isEmptyEdges();

    Node** getVtxArray();

    Edge* getEdge(int i);

    Node* getVtx(int i);

    Node* searchVertex(Node* node);

    Edge* searchEdge(Node* src, Node* dst);

    void deleteI(Node* node);

    void deleteI(Edge* edge);

    void insertNode(Node* newNode);

    void insertEdge(Node* node1, Node* node2);

    void startMatrixA();

    void printMatrixA();

    void printDFS(Node* src);

    bool inVisited(Node* node, Node* visited[10]);

    void _printDFS(Node* src, Node* visited[10], int& it);

    void printDFS(int src);

    void printBFS(int src);

    void printBFS(Node* node);

    void _printBFS(Node* visited[10], Node* queue[10], int front, int last, int& it);

    void printAll();
};

#endif //GRAPH_H

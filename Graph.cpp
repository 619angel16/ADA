#include "Graph.h"
#include <iostream>
#include <ostream>

Graph::Graph()
{
    for (int it = 0; it < 10; it++)
        vtx[it] = nullptr;
    for (int it = 0; it < 45; it++)
        edges[it] = nullptr;
}

Graph::Graph(Node* newNode)
{
    for (int it = 0; it < 10; it++)
        if (vtx[it] == nullptr)
        {
            vtx[it] = newNode;
            break;
        }
    for (int x = 0; x < 10; x++)
        edges[x] = nullptr;
}

Graph::Graph(list<Node*> listNode)
{
    int it = 0;
    for (Node* node : listNode)
    {
        if (it >= 10) break;
        vtx[it++] = node;
    }
    for (int i = 0; i < 45; i++)
    {
        edges[i] = nullptr;
    }
}

void Graph::insertNode(Node* newNode)
{
    for (int it = 0; it < 10; it++)
        if (vtx[it] != newNode)
            if (vtx[it] == nullptr)
            {
                vtx[it] = newNode;
                break;
            }
}

void Graph::insertEdge(Node* src, Node* dst)
{
    if (searchVertex(src) != nullptr && searchVertex(dst) != nullptr)
    {
        if (searchEdge(src, dst) == nullptr)
            for (int i = 0; i < 45; i++)
                if (edges[i] == nullptr)
                {
                    edges[i] = new Edge{src, dst};
                    break;
                }
    }
}

void Graph::startMatrixA()
{
    if (!isEmptyEdges())
    {
        for (auto edge : edges)
        {
            if (edge != nullptr)
            {
                matrixA[edge->src->getId()][edge->dst->getId()] = true;
                matrixA[edge->dst->getId()][edge->src->getId()] = true;
            }
        }
    }
}

void Graph::printMatrixA()
{
    cout << "    0     1     2     3     4     5     6      7     8     9" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << "  ";
        for (int j = 0; j < 10; j++)
        {
            cout << boolalpha;
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }
}

bool Graph::inVisited(Node* node, Node* visited[10])
{
    for (int i = 0; i < 10; i++)
    {
        if (visited[i] == node)
            return true;
    }
    return false;
}


void Graph::printDFS(Node* src)
{
    Node* visited[10] = {};
    if (!isEmptyEdges() && !isEmpty())
    {
        int it = 0;
        _printDFS(src, visited, it);
    }
}

void Graph::_printDFS(Node* src, Node* visited[10], int& it)
{
    if (!isEmptyEdges())
    {
        if (inVisited(src, visited))
            return;
        cout << src->getId() << " --> ";
        visited[it++] = src;
        for (Edge* edge : edges)
        {
            if (edge == nullptr)
                return;
            if (edge->src->getId() == src->getId())
                _printDFS(edge->dst, visited, it);
        }
    }
}

void Graph::printDFS(int src)
{
    Node* visited[10] = {};
    if (!isEmptyEdges() && !isEmpty())
    {
        int it = 0;
        _printDFS(getVtx(src), visited, it);
    }
}

void Graph::printBFS(int src)
{
    Node* visited[10] = {};
    Node* queue[10] = {};
    if (!isEmpty() && !isEmptyEdges())
    {
        int i = 0;
        cout << getVtx(src)->getId() << " --> ";
        visited[i++] = getVtx(src);
        queue[0] = getVtx(src);
        _printBFS(visited, queue, 0, 0, i);
    }
}

void Graph::printBFS(Node* src)
{
    if (searchVertex(src) != nullptr)
    {
        Node* visited[10] = {};
        Node* queue[10] = {};
        if (!isEmpty() && !isEmptyEdges())
        {
            int i = 0;
            cout << src->getId() << " --> ";
            visited[i++] = src;
            queue[0] = src;
            _printBFS(visited, queue, 0, 0, i);
        }
    }
}

void Graph::_printBFS(Node* visited[10], Node* queue[10], int front, int last, int& it)
{
    if (!isEmptyEdges())
    {
        if (front > last)
            return;
        for (auto edge : edges)
        {
            if (edge != nullptr)
                if (edge->src->getId() == queue[front]->getId())
                {
                    if (!inVisited(edge->dst, visited))
                    {
                        cout << edge->dst->getId() << " --> ";
                        visited[it++] = edge->dst;
                        queue[++last] = edge->dst;
                    }
                }
        }
    }
    _printBFS(visited, queue, front + 1, last, it);
}

Node* Graph::getVtx(int i)
{
    return this->vtx[i];
}

Node** Graph::getVtxArray()
{
    return this->vtx;
}

bool Graph::isEmpty()
{
    for (auto node : vtx)
    {
        if (node != nullptr)
            return false;
    }
    return true;
}

bool Graph::isEmptyEdges()
{
    for (auto edge : edges)
    {
        if (edge != nullptr)
            return false;
    }
    return true;
}

Edge* Graph::searchEdge(Node* src, Node* dst)
{
    for (auto edge : edges)
    {
        if (edge != nullptr && edge->src == src && edge->dst == dst)
            return edge;
    }
    return nullptr;
}

Node* Graph::searchVertex(Node* node)
{
    for (auto vtxit : vtx)
    {
        if (vtxit == node)
            return vtxit;
    }
    return nullptr;
}

void Graph::deleteI(Node* node)
{
    if (searchVertex(node) != nullptr)
    {
        for (auto nodeit : vtx)
        {
            if (nodeit == node)
                nodeit == nullptr;
        }
        for (auto edge : edges)
        {
            if (edge->src == node || edge->dst == node)
            {
                edge->src = nullptr;
                edge->dst = nullptr;
            }
        }
    }
}

void Graph::deleteI(Edge* edge)
{
    if (searchEdge(edge->src, edge->dst) != nullptr)
        for (auto edgeit : edges)
        {
            if (edgeit == edge)
            {
                edgeit->src == nullptr;
                edgeit->dst == nullptr;
            }
        }
}

Edge* Graph::getEdge(int i)
{
    return this->edges[i];
}

void Graph::printAll()
{
    for (auto it : vtx)
    {
        if (it != nullptr)
        {
            cout << "Node: " << it->getId() << " Value: " << it->getValue() << endl;
        }
    }
    for (auto it1 : edges)
    {
        if (it1 != nullptr)
        {
            cout << "Edges: " << "Src: " << it1->src->getId() << " " << " Dst: " << it1->dst->getId() << endl;
        }
    }
}

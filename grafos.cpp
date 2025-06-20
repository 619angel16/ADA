#include <list>

#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[]) {

    list<Node *> nodeList;
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    Node e(50);


    Node *ptr_a = &a;
    Node *ptr_b = &b;
    Node *ptr_c = &c;
    Node *ptr_d = &d;
    Node *ptr_e = &e;

    nodeList.emplace_back(ptr_a);
    nodeList.push_back(ptr_b);
    nodeList.push_back(ptr_c);
    nodeList.push_back(ptr_d);
    nodeList.push_back(ptr_e);

    Graph g(nodeList);


    g.insertEdge(ptr_a , ptr_c, 2);
    g.insertEdge(ptr_a, ptr_b, 3);
    g.insertEdge(ptr_b, ptr_e,4);
    g.insertEdge(ptr_c, ptr_d, 5);
    g.insertEdge(ptr_d, ptr_b, 1);
    g.printAll();

    // g.startMatrixA();
    // g.printMatrixA();

    g.printDFS(0);
    cout << endl;
    g.printBFS(0);
    cout << endl;
    g.prim(0);

}

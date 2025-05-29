#include <string>
#include <iomanip>
#include <list>
#include <map>
#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[]) {

    list<Node *> nodeList;
    list<pair<string, string> > adjMatrix;
    Node a("A", 10);
    Node b("B", 20);
    Node c("C", 30);
    Node d("D", 40);

    Node *ptr_a = &a;
    Node *ptr_b = &b;
    Node *ptr_c = &c;
    Node *ptr_d = &d;

    nodeList.emplace_back(ptr_a);
    nodeList.push_back(ptr_b);
    nodeList.push_back(ptr_c);
    nodeList.push_back(ptr_d);

    adjMatrix.emplace_back("A", "B");
    adjMatrix.emplace_back("A", "C");
    adjMatrix.emplace_back("B", "D");

    Graph g(nodeList, adjMatrix);
    g.printAll();
}

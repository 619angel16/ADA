#include <emmintrin.h>

#include "bin3.h"

int main(int argc, char const* argv[])
{
    int store[7] = {5, 6, 2, 1, 10, 9, 3};
    bin3 test3;
    cout << boolalpha;
    for (auto it : store)
    {
        Node* itNode = new Node(it);
        test3.insertNode(itNode);
        cout << it << " ";
    }

    cout << endl << "----------" << endl;
    test3.printOrden(0);
    cout << endl;
    test3.printOrden(1);
    cout << endl;
    test3.printOrden(2);
    cout << endl;
    test3.printOrden(3);
    cout << endl;


    Node* A = new Node(15);
    test3.insertNode(A);
    cout << "----------" << endl;
    test3.printOrden(0);
    cout << endl;
    test3.printOrden(1);
    cout << endl;
    test3.printOrden(2);
    cout << endl;
    test3.printOrden(3);

}

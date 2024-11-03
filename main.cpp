#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    class Node
    {
    public:
        int value;
        Node *sonl;
        Node *sonr;

        Node(int value)
        {
            this->value = value;
            this->sonl = nullptr;
            this->sonr = nullptr;
        }
    };

    class Bin3
    {
    private:
        Node *root;
        Node *findMin(Node *node)
        {
            if (node->sonl != nullptr)
                return findMin(node->sonl);
            else
                return node;
        }
        Node *findMax(Node *node)
        {
            if (node->sonr != nullptr)
                return findMax(node->sonr);
            else
                return node;
        }
        Node *_removeMin(int value, Node *node)
        {
            // Caso base: árbol vacío
            if (node == nullptr)
            {
                return nullptr;
            }

            // Búsqueda del nodo
            if (value < node->value)
            {
                node->sonl = _removeMin(value, node->sonl);
            }
            else if (value > node->value)
            {
                node->sonr = _removeMin(value, node->sonr);
            }
            // Nodo encontrado
            else
            {
                // Caso 1: Nodo hoja
                if (node->sonl == nullptr && node->sonr == nullptr)
                {
                    delete node;
                    return nullptr;
                }
                // Caso 2: Solo hijo izquierdo
                if (node->sonl != nullptr && node->sonr == nullptr)
                {
                    Node *temp = node->sonl;
                    delete node;
                    return temp;
                }
                // Caso 3: Solo hijo derecho
                if (node->sonr != nullptr && node->sonl == nullptr)
                {
                    Node *temp = node->sonr;
                    delete node;
                    return temp;
                }
                // Caso 4: Dos hijos
                Node *temp = findMin(node->sonr);
                node->value = temp->value;
                node->sonr = _removeMin(temp->value, node->sonr);
            }
            return node;
        }
        Node *_removeMax(int value, Node *node)
        {
            // Caso base: árbol vacío
            if (node == nullptr)
            {
                return nullptr;
            }

            // Búsqueda del nodo
            if (value < node->value)
            {
                node->sonl = _removeMax(value, node->sonl);
            }
            else if (value > node->value)
            {
                node->sonr = _removeMax(value, node->sonr);
            }
            // Nodo encontrado
            else
            {
                // Caso 1: Nodo hoja
                if (node->sonl == nullptr && node->sonr == nullptr)
                {
                    delete node;
                    return nullptr;
                }
                // Caso 2: Solo hijo izquierdo
                if (node->sonl != nullptr && node->sonr == nullptr)
                {
                    Node *temp = node->sonl;
                    delete node;
                    return temp;
                }
                // Caso 3: Solo hijo derecho
                if (node->sonr != nullptr && node->sonl == nullptr)
                {
                    Node *temp = node->sonr;
                    delete node;
                    return temp;
                }
                // Caso 4: Dos hijos
                Node *temp = findMax(node->sonl);
                node->value = temp->value;
                node->sonl = _removeMax(temp->value, node->sonl);
            }
            return node;
        }
        void _insert(int value, Node *root)
        {
            if (value < root->value)
                if (root->sonl != nullptr)
                    _insert(value, root->sonl);
                else
                    root->sonl = new Node(value);
            else if (value > root->value)
                if (root->sonr != nullptr)
                    _insert(value, root->sonr);
                else
                    root->sonr = new Node(value);
            else
                cout << "already in the 3" << endl;
        }
        void _printPreO(Node *root)
        {
            cout << root->value << endl;
            if (root->sonl != nullptr)
            {
                _printPreO(root->sonl);
            }
            if (root->sonr != nullptr)
            {
                _printPreO(root->sonr);
            }
            return;
        }
        void _printPostO(Node *root)
        {
            if (root == nullptr)
            {
                return;
            }

            if (root->sonl != nullptr)
            {
                _printPostO(root->sonl);
            }

            if (root->sonr != nullptr)
            {
                _printPostO(root->sonr);
            }

            cout << root->value << endl;
            return;
        }
        void _printInO(Node *root)
        {
            if (root == nullptr)
                return;
            if (root->sonl != nullptr)
            {
                _printInO(root->sonl);
            }
            cout << root->value << endl;

            if (root->sonr != nullptr)
            {
                _printInO(root->sonr);
            }
            return;
        }
        bool _search(int value, Node *root)
        {
            if (root == nullptr)
                return false;
            else if (root->value == value)
                return true;
            else if (value < root->value)
                return _search(value, root->sonl);
            else if (value > root->value)
                return _search(value, root->sonr);
        }
        void _printRightSide(Node *node, int currentLevel, int &maxLevel)
        {
            // Caso base: Si el nodo es nulo, no hay nada que imprimir
            if (node == nullptr)
            {
                return;
            }

            // Si estamos en un nivel mayor al máximo nivel visitado, mostramos el nodo
            if (currentLevel > maxLevel)
            {
                cout << node->value << endl;
                maxLevel = currentLevel;
            }

            // Recorrer primero el hijo derecho y luego el hijo izquierdo
            _printRightSide(node->sonr, currentLevel + 1, maxLevel);
            _printRightSide(node->sonl, currentLevel + 1, maxLevel);
        }

    public:
        Bin3()
        {
            root = nullptr;
        }

        void insert(int value)
        {
            if (root == nullptr)
                root = new Node(value);
            else
                _insert(value, root);
        }

        void printPreO()
        {
            if (root == nullptr)
                cout << "error empty root" << endl;
            else
                _printPreO(root);
        }

        void printPostO()
        {
            if (root == nullptr)
                cout << "error empty root" << endl;
            else
                _printPostO(root);
        }

        void printInO()
        {
            if (root == nullptr)
                cout << "error empty 3" << endl;
            else
                _printInO(root);
        }

        bool search(int value)
        {
            if (_search(value, root))
            {
                cout << "Value: " << value << " found!!" << endl;
                return true;
            }
            else
            {
                cout << "Value not found!!" << endl;
                return false;
            }
        }

        Node *getroot()
        {
            return root;
        }
        void remove(int value, bool MaxMin_MinMax = false)
        {
            if (root == nullptr || !search(value))
            {
                cout << "error empty 3 or element not found" << endl;
            }
            else if (MaxMin_MinMax)
                root = _removeMin(value, root);
            else
                root = _removeMax(value, root);
        }

        void printRightSide(Node *root)
        {
            int maxLevel = -1; // Inicializamos el máximo nivel visitado
            _printRightSide(root, 0, maxLevel);
        }
    };

    cout << "test" << endl;
    Bin3 arbol;
    int insertions[7] = {10, 5, 13, 3, 6, 11, 15};
    for (int i : insertions)
    {
        arbol.insert(i);
    }
    arbol.printPreO();
    cout << "--------" << endl;
    arbol.printPostO();
    cout << "---------" << endl;
    arbol.printInO();
    cout << "---------" << endl;
    arbol.search(4);
    cout << "-------Test remove from tree--------" << endl;
    arbol.remove(3);

    return 0;
}

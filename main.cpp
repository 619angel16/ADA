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
        void _remove(int value, Node *node)
        {
            if (root != nullptr)
            {
                if (value == root->value)
                {
                    root = root->sonl;
                    if (root->sonl != nullptr)
                    {
                        _remove(root->sonl->value, root->sonl);
                    }
                    else
                        return;
                }
                else if (value < root->value)
                    _remove(value, root->sonl);
                else if (value > root->value)
                    _remove(value, root->sonr);
            }
            return;
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
        int _printPreO(Node *root)
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
            return 0;
        }
        int _printPostO(Node *root)
        {
            if (root == nullptr)
            {
                return 0;
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
            return 1;
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
        int _printLeftSide(Node *node)
        {
            int h = 0;
            cout << root->value << endl;
            if (node->sonr != nullptr)
            {
                h += _printLeftSide(node->sonr);
            }
            else if (node->sonl != nullptr)
            {
                h += _printLeftSide(node->sonr);
            }else
                return 1;
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
        void remove(int value)
        {
            if (root == nullptr and !search(value))
            {
                cout << "error empty 3 or element not found" << endl;
            }
            else
                _remove(value, root);
        }

        int sumBin3(Bin3 *arbol)
        {
            if (arbol->getroot() != nullptr)
            {
            }
        }

        void printLeftSide()
        {
            if (root == nullptr)
                cout << "error empty tree" << endl;
            else
                _printLeftSide(root);
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

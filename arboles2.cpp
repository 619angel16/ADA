#include <iostream>

using namespace std;

int main()
{
    class Node
    {
    private:
        int value;
        Node* left;
        Node* right;

    public:
        int getValue() const { return value; }
        Node* getLeft() const { return left; }
        Node* getRight() const { return right; }
        void setRight(Node* node) { right = node; }
        void setLeft(Node* node) { left = node; }

        Node(int value)
        {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    class Bin3
    {
    private:
        Node* root;

        bool _search(Node* node, int value)
        {
            if (node == nullptr)
                return false;
            if (node->getValue() == value)
                return true;
            return _search(node->getLeft(), value) || _search(node->getRight(), value);
        }

        bool _searchO(Node* node, int value)
        {
            if (node == nullptr)
                return false;
            if (node->getValue() == value)
                return true;
            if (node->getValue() < value)
                return _searchO(node->getLeft(), value);
            return _searchO(node->getRight(), value);
        }

        void _insert(Node* sub3, Node* node)
        {
            if (sub3->getValue() < node->getValue())
            {
                if (sub3->getRight() == nullptr)
                {
                    Node* new_node = new Node(node->getValue());
                    sub3->setRight(new_node);
                }
                else
                    _insert(sub3->getRight(), node);
            }
            else if (sub3->getLeft() == nullptr)
            {
                Node* new_node = new Node(node->getValue());
                sub3->setLeft(new_node);
            }
            else
                _insert(sub3->getLeft(), node);
        }

        void _printIn(Node* node)
        {
            if (node->getLeft() != nullptr)
                _printIn(node->getLeft());
            cout << node->getValue() << " - ";
            if (node->getRight() != nullptr)
                _printIn(node->getRight());
        }

        void _printPre(Node* node)
        {
            cout << node->getValue() << " . ";
            if (node->getLeft() != nullptr)
                _printPre(node->getLeft());
            if (node->getRight() != nullptr)
                _printPre(node->getRight());
        }

        void _printPost(Node* node)
        {
            if (node->getLeft() != nullptr)
                _printPost(node->getLeft());
            if (node->getRight() != nullptr)
                _printPost(node->getRight());
            cout << node->getValue() << " * ";
        }

        void _printAn(Node* node, int h)
        {

        }

    public:
        Bin3() { root = nullptr; }
        Node* getRoot() const { return root; }

        bool search(int value, bool isOrdered = true)
        {
            if (root->getValue() == value)
                return true;
            if (!isOrdered)
            {
                return _search(root->getLeft(), value) || _search(root->getRight(), value);
            }
            if (root->getValue() < value)
                return _searchO(root->getRight(), value);
            return _searchO(root->getLeft(), value);
        }

        void insert(Node* node)
        {
            if (root != nullptr)
            {
                if (!search(node->getValue()))
                {
                    if (root->getValue() < node->getValue())
                    {
                        if (root->getRight() != nullptr)
                        {
                            _insert(root->getRight(), node);
                        }
                        else
                        {
                            Node* new_node = new Node(node->getValue());
                            getRoot()->setRight(new_node);
                        }
                    }
                    else if (root->getLeft() != nullptr)
                        _insert(root->getLeft(), node);
                    else
                    {
                        Node* new_node = new Node(node->getValue());
                        getRoot()->setLeft(new_node);
                    }
                }
            }
            else
                root = new Node(node->getValue());
        }

        int getH(Node* node)
        {
            if (node == nullptr)
                return 0;
            int hL = getH(node->getLeft());
            int hR = getH(node->getRight());

            return max(hL, hR) + 1;
        }

        void printIn()
        {
            if (getRoot() == nullptr)
                cout << "Arbol vacio";
            else
                _printIn(getRoot());
        }

        void printPre()
        {
            if (getRoot() == nullptr)
                cout << "Arbol vacio";
            else
                _printPre(getRoot());
        }

        void printPost()
        {
            if (getRoot() == nullptr)
                cout << "Arbol vacio";
            else
                _printPost(getRoot());
        }

        void printAn()
        {
            if (getRoot() == nullptr)
            {
                cout << "Arbol vacio";
            }
            else
                _printAn(getRoot(), getH(getRoot()));
        }
    };
    cout << "test" << endl;
    Bin3 arbol;
    Node insertions[7] = {Node(10), Node(5), Node(13), Node(3), Node(6), Node(11), Node(15)};
    for (Node i : insertions)
    {
        cout << i.getValue() << endl;
        arbol.insert(&i);
    }
    arbol.printIn();
    cout << endl << "--------" << endl;
    arbol.printPre();
    cout << endl << "---------" << endl;
    arbol.printPost();
    cout << endl << "---------" << endl;
    arbol.printAn();
    cout << endl << "---------" << endl;
    arbol.search(4);

    return 0;
}

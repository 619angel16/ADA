#include "bin3.h"
#include <iostream>

bin3::bin3(int value)
{
    this->root = new Node(value);
    this->lft = nullptr;
    this->rgt = nullptr;
}

bin3::bin3(Node* node)
{
    this->root = node;
    this->lft = nullptr;
    this->rgt = nullptr;
}

bin3::bin3(): root(nullptr), lft(nullptr), rgt(nullptr)
{
}

Node* bin3::getroot()
{
    return this->root;
}

int bin3::getHeight()
{
    return _getHeight(this);
}

int bin3::_getHeight(bin3* sub3)
{
    if (sub3 == nullptr)
        return 0;
    int leftHeight = _getHeight(sub3->lft);
    int rightHeight = _getHeight(sub3->rgt);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void bin3::printLevel(int level)
{
    _printLevel(this, level);
}

void bin3::_printLevel(bin3* sub3, int level)
{
    if (sub3 == nullptr)
        return;
    if (level == 0)
        cout << sub3->getroot()->getId() << " ";
    _printLevel(sub3->lft, level - 1);
    _printLevel(sub3->rgt, level - 1);
}

bool bin3::search(int value)
{
    if (this->root == nullptr)
    {
        cout << "Null root error" << endl;
        return false;
    }
    if (this->root->getValue() == value)
        return true;

    if (this->root->getValue() > value)
        return _search(this->lft, value);
    return _search(this->rgt, value);
}

bool bin3::_search(bin3* sub3, int value)
{
    if (sub3 == nullptr)
        return false;

    if (sub3->getroot()->getValue() == value)
        return true;

    if (sub3->getroot()->getValue() > value)
        return _search(sub3->lft, value);
    return _search(sub3->rgt, value);
}

void bin3::insertNode(Node* newNode)
{
    if (this->root != nullptr)
    {
        if (this->root->getId() == newNode->getId())
            cout << "Error node found" << endl;
        else if (newNode->getValue() > this->root->getValue())
        {
            if (this->rgt != nullptr)
            {
                _insertNode(this->rgt, newNode);
            }
            else
            {
                this->rgt = new bin3(newNode);
            }
        }
        else if (newNode->getValue() < this->root->getValue())
        {
            if (this->lft != nullptr)
            {
                _insertNode(this->lft, newNode);
            }
            else
            {
                this->lft = new bin3(newNode);
            }
        }
    }
    else
        this->root = newNode;
}

void bin3::_insertNode(bin3* sub3, Node* newNode)
{
    if (sub3->root->getId() == newNode->getId())
        cout << "Error node found" << endl;
    else if (newNode->getValue() > sub3->root->getValue())
    {
        if (sub3->rgt != nullptr)
        {
            _insertNode(sub3->rgt, newNode);
        }
        else
        {
            sub3->rgt = new bin3(newNode);
        }
    }
    else if (newNode->getValue() < sub3->root->getValue())
    {
        if (sub3->lft != nullptr)
        {
            _insertNode(sub3->lft, newNode);
        }
        else
        {
            sub3->lft = new bin3(newNode);
        }
    }
}

void bin3::printOrden(int choice)
{
    if (choice >= 0 && choice < 4 && this->root != nullptr)
    {
        if (choice == 0)
        {
            cout << this->root->getId() << " ";
            if (this->lft != nullptr)
                _printOrden(this->lft, 0);
            if (this->rgt != nullptr)
                _printOrden(this->rgt, 0);
        }
        if (choice == 1)
        {
            if (this->lft != nullptr)
                _printOrden(this->lft, choice);
            cout << this->root->getId() << " ";
            if (this->rgt != nullptr)
                _printOrden(this->rgt, choice);
        }

        if (choice == 2)
        {
            if (this->lft != nullptr)
                _printOrden(this->lft, choice);
            if (this->rgt != nullptr)
                _printOrden(this->rgt, choice);
            cout << this->root->getId() << " ";
        }
        if (choice == 3)
        {
            _printOrden(this, 3);
        }
    }
}

void bin3::_printOrden(bin3* sub3, int choice)
{
    if (choice >= 0 && choice < 4)
    {
        if (choice == 0)
        {
            //PreOrden
            cout << sub3->root->getId() << " ";
            if (sub3->lft != nullptr)
                _printOrden(sub3->lft, choice);
            if (sub3->rgt != nullptr)
                _printOrden(sub3->rgt, choice);
        }
        if (choice == 1)
        {
            //InOrden
            if (sub3->lft != nullptr)
                _printOrden(sub3->lft, choice);
            cout << sub3->root->getId() << " ";
            if (sub3->rgt != nullptr)
                _printOrden(sub3->rgt, choice);
        }
        if (choice == 2)
        {
            //PostOrden
            if (sub3->lft != nullptr)
                _printOrden(sub3->lft, choice);
            if (sub3->rgt != nullptr)
                _printOrden(sub3->rgt, choice);
            cout << sub3->root->getId() << " ";
        }
        if (choice == 3)
        {
            //Anchura
            int height = getHeight();
            for (int level = 0; level < height; level++)
            {
                printLevel(level);
            }

        }
    }
}

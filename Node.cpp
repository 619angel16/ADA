#include "Node.h"

int Node::id_counter = 0;

Node::Node(int value): value(value)
{
    this->id = id_counter++;
}

Node::Node()
{
    this->value = -1;
    this->id = id_counter++;
}

void Node::setValue(int value)
{
    this->value = value;
}

int Node::getValue()
{
    return this->value;
}

int Node::getId()
{
    return this->id;
}

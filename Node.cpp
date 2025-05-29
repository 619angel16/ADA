//
// Created by USER on 28/05/2025.
//

#include "Node.h"

Node::Node(string name, int value) {
    this->value = value;
    this->name = name;
}

Node::Node(string name) {
    this->value = 0;
    this->name = name;
}

void Node::setValue(int value) {
    this->value = value;
}

void Node::setName(string name) {
    this->name = name;
}

int Node::getValue() {
    return this->value;
}

string Node::getName() {
    return this->name;
}

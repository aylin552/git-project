#include "Node.h"

Node::Node(const std::string& name, Directory* parent) {
    this->name = name;
    this->parent = parent;
}

Node::~Node() {}

const std::string& Node::getName() const { return name; }

Directory* Node::getParent() const { return parent; }
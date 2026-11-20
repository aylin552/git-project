#ifndef NODE_H
#define NODE_H
#include <string>

class Directory;

class Node {
protected:
    std::string name;
    Directory* parent;

public:
    Node(const std::string& name, Directory* parent);
    virtual ~Node();
    virtual bool isDirectory() const = 0;
    const std::string& getName() const;
    Directory* getParent() const;
};
#endif
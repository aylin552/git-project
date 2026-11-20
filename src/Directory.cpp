#include "Directory.h"
#include "Errors.h"

Directory::Directory(const std::string& name, Directory* parent)
    : Node(name, parent) {}

Directory::~Directory() {
    for (int i = 0; i < (int)children.size(); i++)
        delete children[i];
}

bool Directory::isDirectory() const { return true; }

void Directory::insertSorted(Node* node) {
    int pos = 0;
    while (pos < (int)children.size() &&
           children[pos]->getName() < node->getName())
        pos++;
    children.insert(children.begin() + pos, node);
}

int Directory::indexOf(const std::string& childName) const {
    for (int i = 0; i < (int)children.size(); i++)
        if (children[i]->getName() == childName) return i;
    return -1;
}

Node* Directory::find(const std::string& childName) const {
    int i = indexOf(childName);
    if (i == -1) return nullptr;
    return children[i];
}

Directory* Directory::findDirectory(const std::string& childName) const {
    Node* n = find(childName);
    if (n == nullptr || !n->isDirectory()) return nullptr;
    return static_cast<Directory*>(n);
}

File* Directory::findFile(const std::string& childName) const {
    Node* n = find(childName);
    if (n == nullptr || n->isDirectory()) return nullptr;
    return static_cast<File*>(n);
}

Directory* Directory::addDirectory(const std::string& childName) {
    if (find(childName) != nullptr)
        throw GitError ("'" + childName + "' already exists");
    Directory* d = new Directory(childName, this);
    insertSorted(d);
    return d;
}

File* Directory::addFile(const std::string& childName) {
    if (find(childName) != nullptr)
        throw GitError ("'" + childName + "' already exists");
    File* f = new File(childName, this);
    insertSorted(f);
    return f;
}

void Directory::removeFile(const std::string& childName) {
    int i = indexOf(childName);
    if (i == -1)
        throw FileNotFoundError ("File not found: " + childName);
    if (children[i]->isDirectory())
        throw GitError ("'" + childName + "' is a directory");
    delete children[i];
    children.erase(children.begin() + i);
}

int Directory::childCount() const { return (int)children.size(); }

Node* Directory::childAt(int index) const { return children[index]; }
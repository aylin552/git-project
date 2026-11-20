#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>
#include "Node.h"
#include "File.h"

class Directory : public Node {
private:
    std::vector<Node*> children;   // همیشه بر اساس نام مرتب است

    // کپی ممنوع است (چون اشاره‌گر خام داریم و double delete پیش می‌آید)
    Directory(const Directory& other);
    Directory& operator=(const Directory& other);

    void insertSorted(Node* node);

public:
    Directory(const std::string& name, Directory* parent);
    ~Directory();
    bool isDirectory() const;

    int indexOf(const std::string& childName) const;   // اگر نبود -1
    Node* find(const std::string& childName) const;    // اگر نبود nullptr
    Directory* findDirectory(const std::string& childName) const;
    File* findFile(const std::string& childName) const;

    Directory* addDirectory(const std::string& childName);
    File* addFile(const std::string& childName);
    void removeFile(const std::string& childName);

    int childCount() const;
    Node* childAt(int index) const;
};
#endif
#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include "Node.h"

class File : public Node {
private:
    std::vector<std::string> lines;

public:
    File(const std::string& name, Directory* parent);
    bool isDirectory() const;
    const std::vector<std::string>& getLines() const;
    void setLines(const std::vector<std::string>& newLines);
    void appendLine(const std::string& line);
};
#endif
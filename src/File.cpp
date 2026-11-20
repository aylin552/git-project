#include "File.h"

File::File(const std::string& name, Directory* parent) : Node(name, parent) {}

bool File::isDirectory() const { return false; }

const std::vector<std::string>& File::getLines() const { return lines; }

void File::setLines(const std::vector<std::string>& newLines) {
    lines = newLines;
}

void File::appendLine(const std::string& line) {
    lines.push_back(line);
}
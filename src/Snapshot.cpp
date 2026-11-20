#include "Snapshot.h"
#include "Errors.h"
using namespace std;

int Snapshot::indexOf(const string& path) const {
    for (int i = 0; i < (int)files.size(); i++)
        if (files[i].path == path) return i;
    return -1;
}

bool Snapshot::has(const std::string& path) const {
    return indexOf(path) != -1;
}

const vector<std::string>& Snapshot::get(const string& path) const {
    int i = indexOf(path);
    if (i == -1) throw FileNotFoundError("File not found: " + path);
    return files[i].lines;
}

void Snapshot::set(const string& path, const vector<string>& lines) {
    int i = indexOf(path);
    if (i != -1) {
        files[i].lines = lines;
        return;
    }
    FileEntry entry;
    entry.path = path;
    entry.lines = lines;
    int pos = 0;
    while (pos < (int)files.size() && files[pos].path < path) pos++;
    files.insert(files.begin() + pos, entry);   // مرتب‌بودن حفظ می‌شود
}

void Snapshot::remove(const string& path) {
    int i = indexOf(path);
    if (i != -1) files.erase(files.begin() + i);
}

int Snapshot::size() const { return (int)files.size(); }

const FileEntry& Snapshot::at(int index) const { return files[index]; }
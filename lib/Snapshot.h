#ifndef SNAPSHOT_H
#define SNAPSHOT_H

#include <string>
#include <vector>
using namespace std;

struct FileEntry {
   string path;                  // مسیر نسبت به ریشه مخزن
   vector<string> lines;
};

// جای map: یک vector که همیشه بر اساس path مرتب نگه داشته می‌شود
class Snapshot {
private:
    vector<FileEntry> files;

public:
    int indexOf(const string& path) const;   // اگر نبود -1
    bool has(const string& path) const;
    const vector<string>& get(const std::string& path) const;
    void set(const string& path, const vector<std::string>& lines);
    void remove(const string& path);
    int size() const;
    const FileEntry& at(int index) const;
};

struct MergeResult {
    Snapshot merged;
    vector<string> conflicted;
    vector<string> messages;
};
#endif
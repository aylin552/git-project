#ifndef ERROR_H
#define ERROR_H
using namespace std;

#include <string>

class GitError {
private:
    string message;

public:
    GitError(const string& msg) : message(msg) {}
    const char* what() const { return message.c_str(); }
};

class NotARepoError : public GitError {
public:
    NotARepoError(const string& msg) : GitError(msg) {}
};

class FileNotFoundError : public GitError {
public:
    FileNotFoundError(const string& msg) : GitError(msg) {}
};

class InvalidArgumentError : public GitError {
public:
    InvalidArgumentError(const string& msg) : GitError(msg) {}
};
#endif
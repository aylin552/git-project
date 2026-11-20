#include <iostream>
#include <string>
#include "Errors.h"

int main() {
    std::string line;
    while (true) {
        std::cout << "$ ";
        if (!std::getline(std::cin, line)) break;
        if (line == "exit") break;
        try {
            if (!line.empty())
                throw GitError("Unknown command: " + line);
        } catch (const GitError& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}
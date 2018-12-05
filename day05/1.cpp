#include <iostream>
#include <string>
#include <fstream>

int main(void) {
    std::ifstream f("input");
    std::string line;
    std::getline(f, line);
    int i = 0;
    while (line[i]) {
        if (abs(line[i] - line[i+1]) == 32) {
            line.erase(line.begin() + i);
            line.erase(line.begin() + i);
            i = std::max(i-1, 0);
        } else {
            ++i;
        }
    }
    std::cout << line.size();
    return 0;
}

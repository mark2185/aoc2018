#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

int main(void) {
    std::ifstream f("input");
    std::string original_line;
    std::getline(f, original_line);
    int min_size = original_line.size();
    for (char c = 'A'; c < 'Z'; c++) {
        int i = 0;
        std::string line = original_line;
        line.erase(std::remove(line.begin(), line.end(), c), line.end());
        line.erase(std::remove(line.begin(), line.end(), c+32), line.end());
        while (line[i]) {
            if (abs(line[i] - line[i+1]) == 32) {
                line.erase(line.begin() + i);
                line.erase(line.begin() + i);
                i = std::max(i-1, 0);
            } else {
                ++i;
            }
        }
        min_size = std::min(min_size, static_cast<int>(line.size()));
    }
    std::cout << min_size;
    return 0;
}

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stack>

int main(void) {
    std::ifstream f("input");
    std::string original_line;
    std::getline(f, original_line);
    int min_size = original_line.size();
    for (char c = 'A'; c <= 'Z'; c++) {
        std::string line = original_line;
        line.erase(std::remove(line.begin(), line.end(), c), line.end());
        line.erase(std::remove(line.begin(), line.end(), c+32), line.end());
        std::stack<char> stk;
        stk.push('#');
        for (int i = 0; i < static_cast<int>(line.size()); ++i) {
            (abs(stk.top() - line[i]) == 32) ? stk.pop() : stk.push(line[i]);
        }
        min_size = std::min(min_size, static_cast<int>(line.size()));
    }
    std::cout << min_size;
    return 0;
}

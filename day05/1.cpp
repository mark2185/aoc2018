#include <iostream>
#include <string>
#include <fstream>
#include <stack>

int main(void) {
    std::stack<char> stk;
    char c;
    std::cin >> c;
    stk.push(c);
    while (std::cin >> c) {
        (abs(stk.top() - c) == 32) ? stk.pop() : stk.push(c);
    }
    std::cout << stk.size() << std::endl;
    return 0;
}

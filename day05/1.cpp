#include <iostream>
#include <stack>

int main(void) {
    std::stack<char> stk;
    stk.push('#');

    char c;
    while (std::cin >> c) {
        (abs(stk.top() - c) == 32) ? stk.pop() : stk.push(c);
    }
    std::cout << stk.size() - 1 << std::endl;
    return 0;
}

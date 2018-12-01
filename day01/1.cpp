#include <iostream>
#include <numeric>
#include <iterator>

int main(void) {
    std::cout << std::accumulate(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), 0) << '\n';
}

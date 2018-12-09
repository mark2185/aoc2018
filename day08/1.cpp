#include <iostream>

int sum_metadata() {
    int children, mdata;
    std::cin >> children >> mdata;
    int sum = 0;

    for (int i = 0; i < children; ++i) {
        sum += sum_metadata();
    }

    for (int i = 0; i < mdata; ++i) {
        int tmp;
        std::cin >> tmp;
        sum += tmp;
    }
    return sum;
}

int main(void) {
    std::cout<< sum_metadata() << std::endl;
    return 0;
}

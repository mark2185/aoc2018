#include <iostream>
#include <vector>

int sum_metadata() {
    int children, mdata;
    std::cin >> children >> mdata;
    std::vector<int> v(children, 0);

    for (int i = 0; i < children; ++i) {
        v[i] = sum_metadata();
    }

    int sum = 0;
    for (int i = 0; i < mdata; ++i) {
        int tmp;
        std::cin >> tmp;
        if (!children) {
            sum += tmp;
        } else {
            if (tmp <= children) {
                sum += v[tmp-1];
            }
        }
    }
    return sum;
}

int main(void) {
    std::cout<< sum_metadata() << std::endl;
    return 0;
}

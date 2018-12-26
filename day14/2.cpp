#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

std::list<int> getDigits(int number) {
    if (number == 0) {
        return {0};
    }

    std::list<int> digs;
    for(; number > 0; number/=10) {
        digs.push_front(number%10);
    }
    return digs;
}

void print_list(std::list<int> l) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
}

int main(void) {
    int input = 580741;
    std::list<int> recipes;
    recipes.push_back(3);
    recipes.push_back(7);
    auto end = recipes.end();
    auto elfo = recipes.begin();
    auto shocko = recipes.begin();
    shocko++;

    int number = 0;
    int cnt = 2;
    while (true) {
        int new_recipe = *elfo + *shocko;
        for (int d : getDigits(new_recipe)) {
            number *= 10;
            number += d;
            number %= 1000000;
            if (number == input) {
                std::cout << "Weeeeeeeee! " << cnt-5 << std::endl;
                return 0;
            }
            cnt++;
            recipes.insert(end, d);
        }
        int i = *elfo;
        do {
            elfo++;
            if (elfo == recipes.end()) {
                elfo = recipes.begin();
            }
        } while (i-- > 0);

        i = *shocko;
        do {
            shocko++;
            if (shocko == recipes.end()) {
                shocko = recipes.begin();
            }
        } while(i-- > 0);
    }

    return 0;
}

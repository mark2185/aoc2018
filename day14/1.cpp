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
    auto elfo = recipes.begin();
    auto shocko = recipes.begin();
    auto end = recipes.end();
    shocko++;
    while ((int) recipes.size() <= input + 10) {
        int new_recipe = *elfo + *shocko;
        for (int d : getDigits(new_recipe)) {
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

    auto it = recipes.begin();
    std::advance(it, input);
    for (int i = input; i < input + 10; ++i) {
        std::cout << *it++;
    }
    std::cout << std::endl;
    return 0;
}

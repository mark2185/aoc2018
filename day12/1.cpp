#include <iostream>
#include <vector>
#include <map>

int rate_garden(std::string garden, int pad_size) {
    int weight = -pad_size;
    int sum = 0;
    for (int i = 0; i < (int) garden.size(); ++i, ++weight) {
        sum += ((garden[i] == '#') ? weight : 0);
    }
    return sum;
}

int main(void) {
    std::string s;
    getline(std::cin, s);
    std::string garden = s.substr(s.find(":") + 2);

    getline(std::cin, s);
    std::map<std::string, char> patterns;
    while(getline(std::cin, s)) {
        std::string key = s.substr(0, 5);
        patterns[key] = s[9];
    }

    std::string pad= "..........";
    std::string padding = "";
    for (int i = 0; i < 20; ++i) {
        padding += pad;
    }

    garden = padding + garden + padding + padding;

    for (int g = 1; g < 20; ++g) {
        std::string new_garden = garden;
        for (int i = 0; i < (int) garden.size() - 2; ++i) {
            std::string cur = garden.substr(i, 5);
            if (patterns.count(cur) > 0) {
                new_garden[i+2] = patterns[cur];
            } else {
                new_garden[i+2] = '.';
            }
        }
        garden = new_garden;
        std::cout << g << ": " << rate_garden(garden, padding.size()) << std::endl;
    }


    // part 2
    // std::cout << (50000000000-97) * 40 + 5564

    return 0;
}

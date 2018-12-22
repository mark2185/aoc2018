#include <iostream>
#include <map>
#include <vector>

auto time_passage(std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> stars) {
    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> ret;
    for (auto [key, val] : stars) {
        for (auto v : val) {
            auto k = std::make_pair(key.first + v.first, key.second + v.second);
            ret[k].push_back(v);
        }
    }
    return ret;
}

int main(void) {
    FILE *input = fopen("input", "r");
    int x, y, vx, vy;
    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> stars;
    while (fscanf(input, "position=<%d,%d> velocity=<%d,%d>\n", &x, &y, &vx, &vy) == 4) {
        stars[std::make_pair(y, x)].push_back(std::make_pair(vy, vx));
    }
    fclose(input);

    int iter = 0;
    while (iter++ < 10900) {
        stars = time_passage(stars);
    }

    int lower_x = 110;
    int upper_x = 200;

    int lower_y = 185;
    int upper_y = 215;

    while (iter < 10910) {
        std::cout << iter++;

        int star_count = 0;
        for (int i = lower_y; i < upper_y; ++i) {
            for (int j = lower_x; j < upper_x; ++j) {
                star_count += (stars.count(std::make_pair(i, j)) ? 1 : 0);
            }
        }

        std::cout << " " << star_count << std::endl;
        if (star_count > 30) {
            for (int i = lower_y; i < upper_y; ++i) {
                for (int j = lower_x; j < upper_x; ++j) {
                    std::cout << (stars.count(std::make_pair(i, j)) ? "#" : ".");
                }
                std::cout << std::endl;
            }
        }
        stars = time_passage(stars);
    }
    return 0;
}

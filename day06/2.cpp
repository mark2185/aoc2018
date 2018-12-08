#include <iostream>
#include <vector>

int manh(std::pair<int, int> p1, std::pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int sum_manhattan_distances(std::pair<int, int> p, const std::vector<std::pair<int, int>>& v) {
    int sum = 0;
    for (auto par : v) {
        sum += manh(p, par);
    }
    return (sum  < 10000) ? 1 : 0;
}

int main(void) {
    FILE* fp = fopen("input", "r");
    std::vector<std::pair<int, int>> coords;
    int x, y;
    int max_x = 0;
    int max_y = 0;
    while (fscanf(fp, "%d,%d\n", &x, &y) == 2) {
        max_x = std::max(x, max_x);
        max_y = std::max(y, max_y);
        coords.push_back(std::make_pair(x, y));
    }

    int cnt = 0;
    for (int i = 0; i < max_y; ++i) {
        for (int j = 0; j < max_x; ++j) {
            cnt += sum_manhattan_distances(std::make_pair(j, i), coords);
        }
    }

    std::cout << cnt << std::endl;
    fclose(fp);
    return 0;
}

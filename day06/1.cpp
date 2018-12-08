#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

int manh(std::pair<int, int> p1, std::pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int min_manhattan_distance(std::pair<int, int> p, const std::vector<std::pair<int, int>>& v) {
    int min_distance = 1000000000;
    int min_idx = -1;
    int idx = -1;
    for (auto par : v) {
        idx++;
        int tmp = manh(p, par);
        if (tmp < min_distance) {
            min_distance = std::min(min_distance, manh(p, par));
            min_idx      = idx;
        } else if (tmp == min_distance) {
            min_idx = -1;
        }
    }
    return min_idx;
}

int main(void) {
    FILE* fp = fopen("input", "r");
    std::vector<std::pair<int, int>> coords;
    int x, y;
    fscanf(fp, "%d, %d\n", &x, &y);
    x -= 1; y -= 1;
    int upper = y-1, lower = y-1, left = x-1, right = x-1;
    coords.push_back(std::make_pair(x, y));
    while (fscanf(fp, "%d,%d\n", &x, &y) == 2) {
        x -= 1; y -= 1;
        upper = std::min(upper, y);
        lower = std::max(lower, y);
        left  = std::min(left,  x);
        right = std::max(right, x);
        coords.push_back(std::make_pair(x, y));
    }

    int w = right-left;
    int h = lower-upper;
    int *area;
    area = (int*) calloc(w*h, sizeof(int));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            area[i*w+j] = min_manhattan_distance(std::make_pair(j, i), coords);
        }
    }

    std::set<int> eliminated;
    for (int i = 0; i < w; ++i) {
        // first row
        eliminated.insert(area[i]);
        // last row
        eliminated.insert(area[w*(h-1)+i]);
        // first column
        eliminated.insert(area[i*w]);
        // last column
        eliminated.insert(area[(i+1)*w-1]);
    }

    std::map<int, int> hits;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int rm = area[i*w+j];
            if (eliminated.find(rm) == eliminated.end()) {
                if (hits.find(rm) != hits.end()) {
                    hits[rm] += 1;
                } else {
                    hits[rm] = 1;
                }
            }
        }
    }

    int max_val = -1;
    for (auto val : hits) {
        max_val = std::max(max_val, val.second);
    }
    std::cout << max_val << std::endl;

    fclose(fp);
    return 0;
}

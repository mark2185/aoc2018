#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

bool contains(std::vector<std::pair<char, int>> t, char c) {
    for (auto v : t) {
        if (v.first == c) {
            return true;
        }
    }
    return false;
}

void filter_tasks(int time, std::vector<std::pair<char, int>>& tasks) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [time](std::pair<char, int> p) { return p.second == time; }), tasks.end());
}

void cleanup_map(std::map<char, std::vector<char>>& m, char c) {
    m.erase(c);
    for (auto &vals  : m) {
        vals.second.erase(std::remove_if(vals.second.begin(), vals.second.end(), [c](char p) { return p == c; }), vals.second.end());
    }
}

int main(void) {
    FILE* fp = fopen("input", "r");
    char first, second;
    std::map<char, std::vector<char>> m;
    while (fscanf(fp, "Step %c must be finished before step %c can begin.\n", &first, &second) == 2) {
        m[first];
        m[second].push_back(first);
    }

    int time = 0;

    std::vector<std::pair<char, int>> tasks;
    do {
        for (auto t : tasks) {
            if (t.second == time) {
                cleanup_map(m, t.first);
            }
        }
        filter_tasks(time, tasks);
        for (auto val : m) {
            if (val.second.empty()) {
                if (!contains(tasks, val.first)) {
                    if (tasks.size() < 5) {
                        tasks.push_back(std::make_pair(val.first, time + 60 + val.first - '@'));
                    }
                }
            }
        }

        time++;
    } while (!tasks.empty());

    std::cout << time-1 << std::endl;
    fclose(fp);
    return 0;
}

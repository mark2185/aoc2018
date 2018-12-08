#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main(void) {
    FILE* fp = fopen("input", "r");
    char first, second;
    std::map<char, std::vector<char>> m;
    while (fscanf(fp, "Step %c must be finished before step %c can begin.\n", &first, &second) == 2) {
        m[first];
        m[second].push_back(first);
    }

    std::string ret = "";
    while (!m.empty()) {
        for (std::pair<char, std::vector<char>> key_value : m) {
            if (key_value.second.empty()) {
                ret += key_value.first;
                m.erase(key_value.first);
                char tmp = key_value.first;
                for (auto &vals  : m) {
                    vals.second.erase(std::remove_if(vals.second.begin(), vals.second.end(), [tmp](char p) { return p == tmp; }), vals.second.end());
                }
                break;
            }
        }
    }
    std::cout << ret << std::endl;
}

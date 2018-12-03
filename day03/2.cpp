#include <iostream>
#include <vector>
#include <fstream>

#include <boost/algorithm/string.hpp>

int main(void) {
    char fabric[2000][2000] = {0};
    int cnt = 0;
    int x, y, h, w;

    std::string line;
    std::vector<std::string> results;

    std::ifstream file("input");
    while (getline(file, line)) {
        boost::split(results, line, [](char c) { return c == ',' || c == ' ' || c == ':' || c == 'x';});
        x = stoi(results[2]);
        y = stoi(results[3]);
        h = stoi(results[5]);
        w = stoi(results[6]);
        for (int i = x; i < x+h; ++i) {
            for (int j = y; j < y+w; ++j) {
                if (fabric[i][j] == 1) {
                    cnt++;
                }
                fabric[i][j]++;
            }
        }
    }
    std::cout << cnt << std::endl;

    file.clear();
    file.seekg(0, std::ios::beg);

    while (getline(file, line)) {
        boost::split(results, line, [](char c) { return c == '#' || c == ',' || c == ' ' || c == ':' || c == 'x';});
        int ID = stoi(results[1]);
        x = stoi(results[3]);
        y = stoi(results[4]);
        h = stoi(results[6]);
        w = stoi(results[7]);
        bool flag = true;
        for (int i = x; i < x+h; ++i) {
            for (int j = y; j < y+w; ++j) {
                if (fabric[i][j] > 1) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            std::cout << "ID: " << ID << std::endl;
            return 0;
        }
    }
    return 0;
}

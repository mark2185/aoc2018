#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#include "player.h"

std::vector<int> findAll(std::string s, char c) {
    ulong pos = s.find(c);
    std::vector<int> ret;
    while (pos != std::string::npos) {
        ret.push_back(pos);
        pos = s.find(c, pos + 1);
    }
    return ret;
}

void print(std::vector<std::string> map) {
    for (std::string line : map) {
        std::cout << line << std::endl;
    }
    std::cout << std::endl;
}

void print(std::vector<Player> ps) {
    for (Player p : ps) {
        p.toString();
    }
    std::cout << std::endl;
}

struct collision {
    bool value;
    Player cart1;
    Player cart2;
    collision(bool value, Player p1, Player p2) : value(value), cart1(p1), cart2(p2) {};
};

collision collision_detector(std::vector<Player> players) {
    for (int i = 0; i < (int) players.size(); ++i) {
        for (int j = 0; j < (int) players.size(); ++j) {
            if (i == j) {
                continue;
            }
            if (players[i].getPosition() == players[j].getPosition()) {
                return collision(true, players[i], players[j]);
            }
        }
    }
    return {false, players[0], players[0]};
}

void print(std::vector<std::string> map, std::vector<Player> ps) {
    int idx = 0;
    for (std::string line : map) {
        for (Player p : ps) {
            if (p.y == idx) {
                line[p.x] = p.direction;
            }
        }
        idx++;
        std::cout << line << std::endl;
    }
    std::cout << std::endl;
}

int main(void) {
    std::string line;
    std::vector<std::string> map;
    std::map<char, char> chars_tracks { {'<', '-'}, {'>', '-'}, {'^', '|'}, {'v', '|'} };
    std::vector<Player> players;
    int y = 0;
    while(getline(std::cin, line)) {
        std::vector<int> p;
        for (auto [c, t] : chars_tracks) {
            p = findAll(line, c);
            for (int x : p) {
                line[x] = chars_tracks[c];
                players.push_back(Player(x, y, c));
            }
        }
        ++y;
        map.push_back(line);
    }

    for (int iter = 0; ; iter++) {
        std::sort(players.begin(), players.end(), [](Player p1, Player p2) { return p1.x < p2.x; });
        std::sort(players.begin(), players.end(), [](Player p1, Player p2) { return p1.y < p2.y; });

        for (Player& p : players) {
            p.move(map);
            collision col = collision_detector(players);
            if (col.value == true) {
                std::cout << "CRASH! Time of crash: " << iter << std::endl;
                std::cout << "Place of crash: " << col.cart1.x << ", " << col.cart1.y << std::endl;
                return 0;
            }
        }

    }

    return 0;
}

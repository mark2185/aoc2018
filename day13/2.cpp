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

struct collision {
    bool value;
    int cart1;
    int cart2;
    collision(bool value, int p1, int p2) : value(value), cart1(p1), cart2(p2) {};
};

collision collision_detector(std::vector<Player> players) {
    for (int i = 0; i < (int) players.size(); ++i) {
        for (int j = 0; j < (int) players.size(); ++j) {
            if (i == j) {
                continue;
            }
            if (players[i].getPosition() == players[j].getPosition()) {
                return collision(true, i, j);
            }
        }
    }
    return collision(false, -1, -1);
}

int main(void) {
    std::string line;
    std::vector<std::string> map;
    std::map<char, char> chars_tracks { {'<', '-'}, {'>', '-'}, {'^', '|'}, {'v', '|'} };
    std::vector<Player> players;
    for(int y = 0; getline(std::cin, line); ++y) {
        std::vector<int> p;
        for (auto [c, t] : chars_tracks) {
            p = findAll(line, c);
            for (int x : p) {
                line[x] = chars_tracks[c];
                players.push_back(Player(x, y, c));
            }
        }
        map.push_back(line);
    }

    for(int tick = 0; players.size() > 1; ++tick) {
        std::sort(players.begin(), players.end(), [](Player p1, Player p2) { return p1.x < p2.x; });
        std::sort(players.begin(), players.end(), [](Player p1, Player p2) { return p1.y < p2.y; });

        for (int i = 0; i < (int) players.size(); ++i) {
            players[i].move(map);
            auto col = collision_detector(players);
            if (col.value == true ) {
                std::cout << "CRASH! Time of crash: " << tick << std::endl;
                players.erase(std::remove(players.begin(), players.end(), players[col.cart1]), players.end());

                std::cout << "Carts remaining: " << players.size() << std::endl;
                if (i == col.cart1) {
                    i -= 1;
                } else {
                    i -= 2;
                }
            }
        }

    }

    std::cout << "Only 1 remaining" << std::endl;
    players[0].toString();

    return 0;
}

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <map>
#include <string>

class Player {
    private:
        int next_turn = 0;

    public:
        int x;
        int y;
        char direction;
        Player(int x, int y, char direction) : x(x), y(y), direction(direction) {};

        void toString() {
            std::cout << y << ", " << x << std::endl;
        }

        bool operator==(Player p) const { return this->x == p.x && this->y == p.y; };
        bool operator<(Player p) const { return this->x < p.x && this->y < p.y; };

        void move(std::vector<std::string> map);
        std::pair<int, int> getPosition() {
            return {x, y};
        }

};
#endif

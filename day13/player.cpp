#include "player.h"

void move_forward(Player& p) {
    std::map<char, std::pair<int, int>> moves = {
        {'>', {1, 0}},
        {'<', {-1, 0}},
        {'^', {0, -1}},
        {'v', {0, 1}}
    };

    p.x += moves[p.direction].first;
    p.y += moves[p.direction].second;
}

void move_left(Player& p) {
    p.x -= 1;
    p.direction = '<';
}

void move_right(Player& p) {
    p.x += 1;
    p.direction = '>';
}

void move_up(Player& p) {
    p.y -= 1;
    p.direction = '^';
}

void move_down(Player& p) {
    p.y += 1;
    p.direction = 'v';
}

void Player::move(std::vector<std::string> map) {
    std::map<char, std::vector<void (*)(Player&)>> moves = {
        {'>', {move_up, move_right, move_down}},
        {'<', {move_down, move_left, move_up}},
        {'v', {move_right, move_down, move_left}},
        {'^', {move_left, move_up, move_right}}
    };

    std::map<std::pair<char, char>, void (*)(Player&)> turns = {
        { {'>', '\\'}, move_down },
        { {'>', '/'}, move_up },
        { {'<', '\\'}, move_up },
        { {'<', '/'}, move_down },
        { {'^', '\\'}, move_left },
        { {'^', '/'}, move_right },
        { {'v', '\\'}, move_right },
        { {'v', '/'}, move_left },
    };
    if (map[y][x] == '+') {
        moves[direction][next_turn](*this);
        next_turn = (next_turn + 1) % 3;
    } else if (map[y][x] == '-' || map[y][x] == '|') {
        move_forward(*this);
    } else {
        turns[{this->direction, map[y][x]}](*this);
    }
}

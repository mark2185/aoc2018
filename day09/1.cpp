#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

int main(void) {
    int players_num;
    int last_marble;

    scanf("%d players; last marble is worth %d points\n", &players_num, &last_marble);
    last_marble *= 100;

    std::list<int> circle;
    circle.push_back(0);
    circle.push_back(1);

    auto current_idx = circle.end();
    std::vector<int64_t> players(players_num, 0);
    for (int marble = 2, i = 2; marble <= last_marble; ++marble, i = (i+1) % players_num) {
        if ((marble % 23) == 0) {
            for (int j = 0; j < 7; ++j, --current_idx) {
                if (current_idx == circle.begin()) {
                    current_idx = circle.end();
                }
            }

            players[i] += marble + *current_idx;
            circle.erase(current_idx++);
        } else {
            if (++current_idx == circle.end()) {
                current_idx = circle.begin();
            }
            current_idx = circle.insert(++current_idx, marble);
        }
    }
    std::cout << *std::max_element(players.begin(), players.end()) << std::endl;
    return 0;
}

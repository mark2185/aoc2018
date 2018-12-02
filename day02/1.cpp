#include <iostream>
#include <string>
#include <algorithm>
#include <map>

int main(void) {
    std::string line;
    int checksum_2 = 0;
    int checksum_3 = 0;
    while(getline(std::cin, line)) {
        std::map<char, int> m;
        for (int i = 0; i < static_cast<int>(line.length()); ++i) {
            m[line[i]]++;
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == 2) {
                checksum_2 += 1;
                break;
            }
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == 3) {
                checksum_3 += 1;
                break;
            }
        }
    }
    std::cout << checksum_2*checksum_3 << std::endl;

    return 0;
}

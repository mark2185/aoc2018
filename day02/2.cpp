#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

int main(void) {
    std::string line;
    std::vector<std::string> v{ std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>() };
    std::pair<std::string::iterator, std::string::iterator> m;
    for (int i = 0; i < static_cast<int>(v.size()) - 1; ++i) {
        std::cout << v[i] << std::endl;
        for (int j = i+1; j < static_cast<int>(v.size()); ++j) {
            std::cout << v[j] << std::endl;
            m = std::mismatch(v[i].begin(), v[i].end(), v[j].begin());
            std::string s1 = v[i];
            std::string s2 = v[j];
            s1.erase(s1.find(*m.first), 1);
            s2.erase(s2.find(*m.second), 1);
            if (s1 == s2) {
                std::cout << "Match found: \n\t" << s1 << "\n\t" << s2 << std::endl;
                return 0;
            }
        }
    }
    return 0;
}

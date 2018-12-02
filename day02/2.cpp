#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

int main(void) {
    std::vector<std::string> v{ std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>() };
    std::pair<std::string::iterator, std::string::iterator> m;
    for (int i = 0; i < static_cast<int>(v.size()) - 1; ++i) {
        for (int j = i+1; j < static_cast<int>(v.size()); ++j) {
            std::string s1 = v[i];
            std::string s2 = v[j];
            m = std::mismatch(s1.begin(), s1.end(), s2.begin());
            s1.erase(m.first);
            s2.erase(m.second);
            if (s1 == s2) {
                std::cout << "Match found: \n\t" << s1 << "\n\t" << s2 << std::endl;
                return 0;
            }
        }
    }
    return 0;
}

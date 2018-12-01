#include <iostream>
#include <fstream>
#include <set>

using namespace std;
int main(void) {
    ifstream file("input");
    set<int> s;
    int sum = 0;
    if (file) {
        while (true) {
            int num;
            while (file >> num) {
                int size_before = s.size();
                sum += num;
                s.insert(sum);
                int size_after = s.size();
                if (size_before == size_after) {
                    cout << sum << endl;
                    return 0;
                }
            }
            file.clear();
            file.seekg(0, ios::beg);
        }
    } else {
        cout << "No file named input\n";
    }
    return 0;
}

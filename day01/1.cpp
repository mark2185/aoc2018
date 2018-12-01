#include <iostream>
#include <fstream>
#include <set>

using namespace std;
int main(void) {
    int sum = 0;
    int num;
    ifstream file("input");
    if (file) {
        set<int> s;
        while (file >> num) {
            sum += num;
        }
        cout << sum << endl;
    } else {
        cout << "No file named input\n";
    }
    return 0;
}

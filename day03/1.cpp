#include <iostream>

int main(void) {
    char fabric[2000][2000] = {0};
    int cnt = 0;
    int ID, x, y, h, w;

    FILE *fp = fopen("input", "r");
    while (fscanf(fp, "#%d @ %d,%d: %dx%d\n", &ID, &x, &y, &h, &w) == 5) {
        for (int i = x; i < x+h; ++i) {
            for (int j = y; j < y+w; ++j) {
                if (fabric[i][j] == 1) {
                    cnt++;
                }
                fabric[i][j]++;
            }
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}

#include <iostream>

int main(void) {
    char fabric[1000][1000] = {0};
    int cnt = 0;
    int ID, x, y, h, w;

    FILE *fp = fopen("input", "r");
    while (fscanf(fp, "#%d @ %d,%d: %dx%d\n", &ID, &x, &y, &h, &w) == 5) {
        for (int i = x; i < x+h; ++i) {
            for (int j = y; j < y+w; ++j) {
                if (fabric[i][j]++ == 1) {
                    cnt++;
                }
            }
        }
    }

    fseek(fp, 0, SEEK_SET);
    while (fscanf(fp, "#%d @ %d,%d: %dx%d\n", &ID, &x, &y, &h, &w) == 5) {
        bool flag = true;
        for (int i = x; i < x+h; ++i) {
            for (int j = y; j < y+w; ++j) {
                if (fabric[i][j] > 1) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            std::cout << "ID: " << ID << std::endl;
            return 0;
        }
    }
    fclose(fp);
    return 0;
}

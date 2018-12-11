#include <iostream>
#include <vector>

int calculate_power(int x, int y, int grid_serial) {
    int rack_id = x + 10;
    int power = (rack_id * y + grid_serial) * rack_id;
    return ((power / 100) % 10) - 5;
}

int main(void) {
    int grid_serial_num = 9306;
    std::vector<std::vector<int>> field(301, std::vector<int>(301));
    for (int i = 1; i < 301; ++i) {
        for (int j = 1; j < 301; ++j) {
            field[j][i] = calculate_power(j, i, grid_serial_num);
        }
    }

    int max_sum = 0;
    int max_sum_x, max_sum_y;
    for (int block_size = 1; block_size < 301; ++block_size) {
        for (int i = 1; i <= 301 - block_size; ++i) {
            for (int j = 1; j <= 301 - block_size; ++j) {
                int suma = 0;
                for (int u = 0; u < block_size; ++u) {
                    for (int v = 0; v < block_size; ++v) {
                        suma += field[i+u][j+v];
                    }
                }
                if (suma > max_sum) {
                    max_sum = suma;
                    max_sum_x = i;
                    max_sum_y = j;
                }
                max_sum = std::max(suma, max_sum);
            }
        }
        std::cout << max_sum_x << "," << max_sum_y << "," << block_size << "(" << max_sum << ")" << std::endl;
    }
    std::cout << max_sum_x << "," << max_sum_y << max_sum << std::endl;
    return 0;
}

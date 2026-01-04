#include <fstream>
#include <vector>

int main() {
    std::vector<int> coords = {
        2, 5,  2, 6,  3, 5,  3, 6,  4, 7,  
        1, 10, 2, 10, 2, 11, 3, 11, 4, 10,

        10, 35, 10, 36, 11, 34, 11, 35, 11, 36, 11, 37,
        12, 34, 12, 35, 12, 36, 13, 35, 14, 35,

        25, 65, 25, 66, 26, 66, 4, 67, 5, 67, 5, 68,
        6, 68, 6, 69, 7, 69, 7, 70,

        18, 10, 19, 10, 19, 11, 20, 11, 20, 12,
        21, 12, 21, 13, 22, 13,

        18, 60, 18, 61, 19, 62, 20, 63, 21, 64,
        22, 65, 23, 66, 24, 67, 24, 68, 23, 69,

        0, 0,   0, 79,  24, 0,  24, 79, 12, 5,
        5, 40,  20, 40, 12, 75, 8, 20,  15, 55
    };

    std::ofstream f("battle_islands.bin", std::ios::binary);

    if (f) {
        f.write(reinterpret_cast<const char*>(coords.data()), coords.size() * sizeof(int));
        f.close();
    }

    return 0;
}

#include <fstream>

int main() {
    const int ROWS = 25, COLS = 80, COUNT = 50;
    int coords[] = {
        2, 5, 5, 8, 8, 12, 12, 3, 15, 7, 18, 15, 3, 18, 7, 22, 10, 25, 14, 28,
        1, 30, 4, 35, 9, 38, 13, 42, 17, 45, 20, 48, 22, 52, 6, 55, 11, 58, 16, 62,
        2, 65, 5, 68, 8, 72, 12, 75, 15, 78, 19, 70, 21, 66, 23, 63, 4, 60, 7, 57,
        0, 10, 24, 20, 10, 10, 14, 15, 18, 25, 3, 40, 7, 45, 12, 50, 16, 55, 20, 60,
        1, 1, 23, 79, 6, 33, 11, 44, 17, 27, 21, 38, 4, 50, 9, 61, 14, 72, 19, 5
    };

    std::ofstream f("battle_islands.bin", std::ios::binary);
    f.write((char*)&ROWS, 4);
    f.write((char*)&COLS, 4);
    f.write((char*)&COUNT, 4);
    f.write((char*)coords, sizeof(coords));
    return 0;
}

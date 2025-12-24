#include <cstdlib>
#include <ctime>
#include <vector>
#include "Game.h"
#include <algorithm>
Game::Game(int rab, int pre)
{
    // 初始化随机数种子
    std::srand(std::time(nullptr));
}

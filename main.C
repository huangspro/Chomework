#include <ncurses.h>
#include "Gui.h"
#include <sys/time.h>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <cstddef>
#include "Game.h"
using namespace std;


int main(int argc, char* argv[])
{
    srand(time(0));
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t oldTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    time_t currentTime =  oldTime;
    Game game(std::atoi(argv[1]),std::atoi(argv[2]));
    while (true) {
        gettimeofday(&time_now, NULL);
        currentTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 500);
        if (currentTime - oldTime < 100) {usleep(22);continue;}
        game.update();
        oldTime = currentTime;
    }
    return 0;
}

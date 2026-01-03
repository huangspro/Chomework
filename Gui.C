#include <ncurses.h>
#include "Gui.h"
#include <cstring>
using namespace std;

void Gui::init() {
    initscr();                  /* Start curses mode              */
    refresh();                  /* Print it on to the real screen */
    win = stdscr;
    refresh();
    curs_set(0);
    wrefresh(win);
    noecho();
    cbreak();
    keypad(win, true);
    nodelay(win, true);
    flushinp();
    start_color();
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_BLACK);
}

int Gui::get() {
    int c = wgetch(win);
    flushinp();
    return c;
}

void Gui::paintat(size_t rw, size_t cl, char c) {
    mvwaddch(win, rw, cl, c);
    return;
}

void Gui::printMsg(int row, int col, const char* prompt) {
    mvwprintw(win, row, col, prompt);
}

void Gui::clear() {
    werase(win);
}

void Gui::redraw() {
    wrefresh(win);
}

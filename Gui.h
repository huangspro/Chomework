#ifndef _GUI_H_
#define _GUI_H_
#include <ncurses.h>

class Gui {
    size_t row;
    size_t col;
    WINDOW* win;
public:
    Gui ():row(25),col(80) {init();}
    ~Gui() {endwin();}
    void init();
    int get();
    void paintat(size_t, size_t, char);
    void printMsg(int row, int col, const char* prompt);
    void clear();
    void redraw();
    void end() {endwin();}
};
#endif

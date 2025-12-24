#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include "Gui.h"
#include<algorithm>

using namespace std;

class Game {
	Gui gui;

public:
	Game(int,int);
	~Game() ;
	void paintAt(size_t r, size_t c, char x);
	void printMsg(size_t r, size_t c, const char* s);
	void update();
	void updateItems();
	
};
#endif

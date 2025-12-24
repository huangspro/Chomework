#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include "Gui.h"
#include "Animal.h"
#include "Grass.h"
#include<algorithm>

using namespace std;

class Game {
	Gui gui;
	std::vector <Grass*> G;
	std::vector <Animal*> A;
public:
	Game(int,int);
	~Game() ;
	void paintAt(size_t r, size_t c, char x);
	void printMsg(size_t r, size_t c, const char* s);
	void update();
	void updateItems();
	Animal* pick(int, int, int, int);
	void add(Animal*);
  void kill(Animal*);
  Grass* pick_grass(int r, int c);
};
#endif

#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include "Gui.h"
#include<algorithm>

using namespace std;

class Game {
	Gui gui;
	vector<Ship*> AllShips;
	vector<Weapon*> AllWeapons;
	vector<Island*> AllIslands;
	vector<Bomber*> AllBombers;
	vector<Pack*> AllPacks;
public:
	Game();
	Game(int);
	~Game() ;
	void paintAt(size_t r, size_t c, char x);
	void printMsg(size_t r, size_t c, const char* s);
	void update();
	void updateItems();
};
#endif

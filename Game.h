#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include "Gui.h"
#include "Gunboat.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Player.h"
#include "Bullet.h"
#include "Torpedo.h"
#include "Missile.h"
#include "Bomber.h"
#include "Island.h"
#include "Pack.h"
#include "Ship.h"
#include<algorithm>

using namespace std;

class Game {
	Gui gui;
	vector<Ship*> AllShips;
	vector<Weapon*> AllWeapons;
	vector<Island*> AllIslands;
	vector<Bomber*> AllBombers;
	vector<Pack*> AllPacks;
	Player* player;
public:
	Game();
	Game(int);
	~Game() ;
	void paintAt(size_t r, size_t c, char x);
	void printMsg(size_t r, size_t c, const char* s);
	void update();
	void updateItems();
	void kill(Item*);
	Island* getIsland(size_t, size_t);
	Ship* getShip(size_t, size_t);
};
#endif

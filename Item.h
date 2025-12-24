//Item is the basic class generating every sub class
#ifndef _ITEM_H_
#define _ITEM_H_
//define the type of each item
#define MAXROW 30
#define MAXCOL 80

#define Bullet 1
#define Torpedo 2
#define Missile 3

#define Bomber 4
#define Cruiser 5
#define Destroyer 6
#define Gunboat 7

#define Island 8
#define Medical 9
#define Weapon 10

#define Player 11
//define 4 direction
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
//====================================
#include <iostream>
using namespace std;
class Game;
class Item
{
public:
	size_t row;
	size_t col;
	size_t type;
	size_t direction;
	Game *game;
	
	Item(Game*, size_t, size_t, size_t);
	virtual ~Item() {}
	
	virtual void update();
	virtual void move(size_t direction, size_t step);
	virtual void remove();
	virtual void show();
};
#endif

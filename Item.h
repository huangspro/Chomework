//Item is the basic class generating every sub class
#ifndef _ITEM_H_
#define _ITEM_H_
//define the type of each item
#define MAXROW 30
#define MAXCOL 80

#define Bullet_n 1
#define Torpedo_n 2
#define Missile_n 3

#define Bomber_n 4
#define Cruiser_n 5
#define Destroyer_n 6
#define Gunboat_n 7

#define Island_n 8
#define Medical_n 9
#define Weapon_n 10

#define Player_n 11
//define 4 direction
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

//define the speed of each item
#define Bullet_v 2
#define Torpedo_v 2
#define Missile_v 1
#define Player_v 5
#define Bomber_v 10
#define Cruiser_v 5
#define Destroyer_v 5
#define Gunboat_v 3

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
	size_t direction = UP;
	size_t v; //v is thee speed of item. one item move after per v turns
	size_t tem=0; //this is for remember the last move
	bool showable=true;
	Game *game;
	
	Item(Game*, size_t, size_t, size_t,size_t);
	virtual ~Item() {}
	
	virtual void update();
	virtual void move(size_t direction, size_t step);
	virtual void remove(){};
	virtual void show(){};
};
#endif

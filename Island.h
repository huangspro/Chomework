#ifndef _ISLAND_H_
#define _ISLAND_H_

#include "Item.h"
class Game
class Island : public Weapon{
public:
  Island(Game* g, size_t r, size_t c):Weapon(g,r,c,0,Island_n){}
  void move(size_t direction, size_t step);
  void show();
  void remove();
  void update();
};
#endif

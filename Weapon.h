#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Item.h"
class Game;
class Weapon : public Item{
public:
  int sender; //0 is player, 1 is enemy
  int t=5;
  Weapon(Game* g, size_t r, size_t c, size_t v,size_t t, int sender):Item(g,r,c,v,t),sender(sender){}
  virtual ~Weapon(){};
  virtual void move(size_t direction, size_t step);
  virtual void show(){};
  virtual void remove();
  virtual void update(){Item::update();};
  virtual void check_crash(){};
};

#endif

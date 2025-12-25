#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Item.h"

class Weapon : public Item{
public:
  Weapon(Game* g, size_t r, size_t c, size_t v,size_t t):Item(g,r,c,v,t){}
  void virtual move(size_t direction, size_t step){Item::move(direction, step);}
  void virtual show();
  void virtual remove();
  void virtual update();
};

#endif

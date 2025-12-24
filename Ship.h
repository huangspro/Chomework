#ifndef _SHIP_H_
#define _SHIP_H_

#include "Item.h"

class Ship : public Item{
public:
  size_t health, bullet, missile, torpedoes;
  Ship(Game* g, size_t r, size_t c, size_t t):Item(g,r,c,t){}
  
  virtual void move(size_t direction, size_t step);
  virtual void remove();
  virtual void show();
};
#endif

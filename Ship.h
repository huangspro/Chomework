#ifndef _SHIP_H_
#define _SHIP_H_

#include "Item.h"

class Ship : public Item{
public:
  size_t health, bullet, missile, torpedoes;
  Ship(Game* g, size_t r, size_t c, size_t t):Item(g,r,c,t){
    if(t==Gunboat){
      health=1;
      bullet=10;
      missile=torpedoes=0;
    else if(t==Destroyer){
      health=10;
      bullet=10;
      Torpedoes=2;
      missile=0;
    }
    else if(t==Cruiser){
      health=100;
      bullet=30;
      missile=2;
      Torpedoes=0;
    }
  }
  
  virtual void move(size_t direction, size_t step);
  virtual void remove();
  virtual void show();
}
#endif

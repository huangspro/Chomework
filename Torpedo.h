#ifndef _TORPEDO_H_
#define _TORPEDO_H_

#include "Weapon.h"
class Game;
class Torpedo : public Weapon{
public:
  Torpedo(Game* g, size_t r, size_t c,int sender):Weapon(g,r,c,Torpedo_v,Torpedo_n,sender){}
  void move(size_t direction, size_t step);
  void show();
  void remove(){};
  void update();
  void check_crash();
};
#endif

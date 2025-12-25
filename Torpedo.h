#ifndef _TORPEDO_H_
#define _TORPEDO_H_

#include "Weaopn.h"
class Game
class Torpedo : public Weapon{
public:
  Torpedo(Game* g, size_t r, size_t c, size_t t):Weapon(g,r,c,Torpedo_v,Torpedo_n){}
  move(size_t direction, size_t step);
  show();
  remove();
  update();
};
#endif

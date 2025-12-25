#ifndef _MISSILE_H_
#define _MISSILE_H_

#include "Weaopn.h"
class Game
class Missile : public Weapon{
public:
  Missile(Game* g, size_t r, size_t c, size_t t):Weapon(g,r,c,Missile_v,Missile_n){}
  move(size_t direction, size_t step);
  show();
  remove();
  update();
};
#endif

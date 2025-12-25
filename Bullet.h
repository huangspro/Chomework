#ifndef _BULLET_H_
#define _BULLET_H_

#include "Weaopn.h"
class Game
class Bullet : public Weapon{
public:
  Bullet(Game* g, size_t r, size_t c, size_t t):Weapon(g,r,c,Bullet_v,t){}
  move(size_t direction, size_t step);
  show();
  remove();
  update();
};
#endif

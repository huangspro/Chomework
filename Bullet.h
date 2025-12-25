#ifndef _BULLET_H_
#define _BULLET_H_

#include "Weapon.h"
class Game;
class Bullet : public Weapon{
public:
  Bullet(Game* g, size_t r, size_t c, size_t t):Weapon(g,r,c,Bullet_v,t){}
  void move(size_t direction, size_t step);
  void show();
  void remove();
  void update();
};
#endif

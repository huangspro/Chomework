#ifndef _MISSILE_H_
#define _MISSILE_H_

#include "Weapon.h"
class Game;
class Missile : public Weapon{
public:
  Missile(Game* g, size_t r, size_t c,int sender):Weapon(g,r,c,Missile_v,Missile_n,sender){}
  void move(size_t direction, size_t step);
  void show();
  void remove(){};
  void update(){};
  void check_crash();
};
#endif

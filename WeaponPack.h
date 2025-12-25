#ifndef _PACK_H_
#define _PACK_H_

#include "Pack.h"
class Game;
class WeaponPack{
public:
  WeaponPack(Game* g, size_t r, size_t c):Pack(g,r,c,Weapon_n){}
  void move(size_t direction, size_t step);
  void show();
  void remove();
  void update();
  void check_crash();
};

#endif

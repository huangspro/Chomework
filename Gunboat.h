#ifndef _GUNBOAT_H_
#define _GUNBOAT_H_
#include "Ship.h"
class Game;
class Gunboat : public Ship{
public:
  Gunboat(Game* g, size_t r, size_t c):Ship(g,r,c,Gunboat_v,Gunboat_n){
    bullet=10;
    health=1;
    missile=torpedoes=0;
  }
  void move(size_t direction, size_t step);
  void show();
  void fire();
  void update();
  void remove();
};

#endif

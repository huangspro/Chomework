#ifndef _GUNBOAT_H_
#define _GUNBOAT_H_

class Gunboat : public Ship{
public:
  Gunboat(Game* g, size_t r, size_t c):Ship(g,r,c,Gunboat){
    health=1;
    bullet=10;
    missile=torpedoes=0;
  }
  void move(size_t direction, size_t step);
  void show();
};

#endif

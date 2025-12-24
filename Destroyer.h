#ifndef _DESTROYER_H_
#define _DESTROYER_H_

class Destroyer : public Ship{
public:
  Destroyer(Game* g, size_t r, size_t c):Ship(g,r,c,Destroyer){
    health=1;
    bullet=10;
    missile=torpedoes=0;
  }
  void move(size_t direction, size_t step);
  void show();
};

#endif

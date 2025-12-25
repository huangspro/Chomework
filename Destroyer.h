#ifndef _DESTROYER_H_
#define _DESTROYER_H_

class Destroyer : public Ship{
public:
  Destroyer(Game* g, size_t r, size_t c):Ship(g,r,c,Destroyer_v,Destroyer_n){
    health=10;
    bullet=10;
    missile=0;
    torpedoes=2;
  }
  void move(size_t direction, size_t step);
  void show();
  void fire();
  void update();
};

#endif

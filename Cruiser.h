#ifndef _CRUISER_H_
#define _CRUISER_H_

class Cruiser : public Ship{
public:
  Cruiser(Game* g, size_t r, size_t c):Ship(g,r,c,Cruiser_v,Cruiser_n){
    health=100;
    bullet=30;
    missile=2;
    torpedoes=0;
  }
  void move(size_t direction, size_t step);
  void show();
  void fire();
  void update();
};

#endif

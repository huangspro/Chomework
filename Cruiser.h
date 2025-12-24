#ifndef _CRUISER_H_
#define _CRUISER_H_

class Cruiser : public Ship{
public:
  Cruiser(Game* g, size_t r, size_t c):Ship(g,r,c,Cruiser){
    health=1;
    bullet=10;
    missile=torpedoes=0;
  }
  void move(size_t direction, size_t step);
  void show();
};

#endif

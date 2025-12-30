#ifndef _BOMBER_H_
#define _BOMBER_H_
#include "Item.h"

class Game;
class Bomber : public Item{
public:
  size_t bullet,health,missile,torpedo;
  Bomber(Game* g, size_t r, size_t c):Item(g,r,c,Bomber_v,Bomber_n){
    bullet=3;
    health=10000;
    missile=0;
    torpedo=1;
    direction=RIGHT;
  }
  void move(size_t d, size_t s);
  void show();  
  void fire();  
  void remove();//do nothing, for the bomber can't be destroy
  void update();
};

#endif

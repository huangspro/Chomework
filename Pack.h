#ifndef _PACK_H_
#define _PACK_H_

#include "Item.h"
class Game;
class Pack : public Item{
public:
  Pack(Game* g, size_t r, size_t c, size_t t):Item(g,r,c,0,t){}
  virtual ~Pack(){};
  virtual void move(size_t direction, size_t step){};
  virtual void show(){};
  virtual void remove(){};
  virtual void update(){Item::update();};
  virtual void check_crash(){};
};
#endif

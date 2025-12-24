#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Item.h"

class Weapon : public Item{
public:
  virtual move();
  virtual check_crash();
  virtual show();
  virtual remove();
};

#endif

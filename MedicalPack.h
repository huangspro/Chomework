#ifndef _MEDICALPACK_H_
#define _MEDICALPACK_H_

#include "Pack.h"
#include "Ship.h"


class Game;
class MedicalPack : public Pack{
public:
  MedicalPack(Game* g, size_t r, size_t c):Pack(g,r,c,MedicalPack_n){}
  void move(size_t direction, size_t step){};
  void show();
  void remove();
  void update();
  void check_crash();
  void tem_f(Ship*);
};

#endif

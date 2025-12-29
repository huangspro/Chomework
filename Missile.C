#include "Missile.h"
#include "Game.h"

void Missile::move(size_t direction, size_t step){
  //use father class move
  Weapon::move(direction,step);
}

void Missile::show(){
  game->paintAt(row, col, '*');
}

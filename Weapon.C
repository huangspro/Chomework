#include "Weapon.h"
#include "Game.h"

void Weapon::remove(){
  game->kill(this);
}

void Weapon::move(size_t direction, size_t step){
  if(type!=Missile_n && game->getIsland(row,col))remove();
  Item::move(direction, step);
}

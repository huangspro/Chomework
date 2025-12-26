#include "Gunboat.h"
#include "Game.h"
#include<stdlib.h>

void Gunboat::move(size_t direction, size_t step){
  int d[]={1,2,3,4};
  Ship::move(d[rand()%4], 1);
}

void Gunboat::show(){
  game->paintAt(row, col, 'o');
}
/*
void Gunboat::fire(){
  game->addWeapon(row, col, direction, Bullet);
}

*/

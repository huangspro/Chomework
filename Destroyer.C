#include "Destroyer.h"
#include "Game.h"
#include<stdlib.h>

void Destroyer::move(size_t direction, size_t step){
  int d[]={1,2,3,4};
  Ship::move(d[rand()%4], 1);
}

void Destroyer::show(){
  game->paintAt(row, col, 'O');
}
/*
void Destroyer::fire(){
  if(rand()%2==0)game->addWeapon(row, col, direction, Bullet);
  else game->addWeapon(row, col, direction, Torpedo);
}*/

void Destroyer::update(){
  Ship::update();
  move(direction,1);
  if(rand()%10<2)fire();
}

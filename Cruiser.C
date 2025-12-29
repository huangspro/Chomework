#include "Cruiser.h"
#include "Game.h"
#include<stdlib.h>

void Cruiser::move(size_t direction, size_t step){
  size_t d[]={3,4};
  Ship::move(d[rand()%2], 1);
}

void Cruiser::show(){
  game->paintAt(row, col, '<');
  if(col<MAXCOL)game->paintAt(row, col+1, '>');
}
/*
void Cruiser::fire(){
  if(rand()%2==0)game->addWeapon(row, col, direction, Bullet);
  else game->addWeapon(row, col, direction, Missile);
}*/

void Cruiser::fire(){

}

void Cruiser::update(){
  Ship::update();
  move(direction, 1);
  if(rand()%10<3)fire();
}

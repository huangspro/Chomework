#include "Gunboat.h"
#include "Game.h"
#include<stdlib.h>

void Gunboat::move(size_t direction,size_t step){
  int d[]={1,2,3,4};
  Ship::move(d[rand()%4], 1);
}

void Gunboat::show(){
  Item::show();
  game->paintAt(row, col, 'o');
}

void Gunboat::fire(){
  if(bullet<=0)remove();
  int d[]={1,2,3,4};
  game->addWeapons(row, col, Bullet_n,d[rand()%4], 1);
  bullet--;
}


void Gunboat::update(){
  if(health<=0)remove();
  Ship::update();
  move(direction, 1);
  fire();
}

void Gunboat::remove(){
  game->kill(this);
}

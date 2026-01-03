#include "Cruiser.h"
#include "Game.h"
#include<stdlib.h>

void Cruiser::move(size_t direction, size_t step){
  size_t d[]={3,4};
  Ship::move(d[rand()%2], 1);
}

void Cruiser::show(){
  Item::show();
  game->paintAt(row, col, '<');
  if(col<MAXCOL)game->paintAt(row, col+1, '>');
}

void Cruiser::fire(){
  int d[]={1,2,3,4};
  if(bullet<=0 && missile<=0)remove();
  switch(rand()%2){
    case 0:
      if(bullet<=0)return;
      game->addWeapons(row, col, Bullet_n,d[rand()%4], 1);
      bullet--;break;
    case 1:
      if(missile<=0)return;
      game->addWeapons(row, col, Missile_n,d[rand()%4], 1);
      missile--;break;
  }
}

void Cruiser::update(){
  if(health<=0)remove();
  Ship::update();
  move(direction, 1);
  if(rand()%10<1)fire();
}

void Cruiser::remove(){
  game->kill(this);
}

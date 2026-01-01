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


void Destroyer::update(){
  Ship::update();
  move(direction,1);
  if(rand()%10<2)fire();
}

void Destroyer::fire(){
  if(bullet<=0 && torpedoes<=0)remove();
  switch(rand()%2){
    case 0:
      if(bullet<=0)return;
      game->addWeapons(row, col, Bullet_n,direction, 1);
      bullet--;break;
    case 1:
      if(missile<=0)return;
      game->addWeapons(row, col, Torpedo_n,direction, 1);
      torpedoes--;break;
  }
}

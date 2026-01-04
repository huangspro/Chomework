#include "Torpedo.h"
#include "Game.h"

void Torpedo::move(size_t direction, size_t step){
  if(row <=1 || row >=MAXROW-1 || col==MAXCOL-1 || col==1)remove();
  if(game->getIsland(row,col))remove();
  //use father class move
  Weapon::move(direction,step);
  
}

void Torpedo::show(){
  game->paintAt(row, col, '=');
}

void Torpedo::check_crash(){
  if(t>0)return;
  Ship* tem=game->getShip(row,col);
  if(tem!=nullptr){
    tem->health-=100;
    remove();
  }
}

void Torpedo::update(){
  t--;
  Weapon::update();
  move(direction,1);
  check_crash();
}

void Torpedo::remove(){
  game->kill(this);
}

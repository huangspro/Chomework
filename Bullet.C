#include "Bullet.h"
#include "Game.h"

void Bullet::move(size_t direction, size_t step){
  if(row <=1 || row >=MAXROW-1 || col==MAXCOL-1 || col==1)remove();
  if(game->getIsland(row,col))remove();
  //use father class move
  Weapon::move(direction,step);
}

void Bullet::show(){
  game->paintAt(row, col, direction==UP|direction==DOWN?'|':'-');
}

void Bullet::update(){
  Item::update();
  move(direction,1);
  //check_crash();
}

void Bullet::check_crash(){
  Ship* tem=game->getShip(row,col);
  if(tem!=nullptr){
    tem->health-=1;
  }
}

void Bullet::remove(){
  game->kill(this);
}

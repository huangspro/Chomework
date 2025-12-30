#include "Missile.h"
#include "Game.h"

void Missile::move(size_t direction, size_t step){
  //use father class move
  Weapon::move(direction,step);
}

void Missile::show(){
  game->paintAt(row, col, '*');
}

void Missile::check_crash(){
  Ship* tem=game->getShip(row,col);
  if(tem==nullptr)return;
  else if(tem!=game->player && sender==0){
    tem->health-=5;
    remove();
  }
  else if(tem==game->player && sender!=0){
    game->player->health-=5;
    remove();
  }else{
    remove();
  }
}

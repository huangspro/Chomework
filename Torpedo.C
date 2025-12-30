#include "Torpedo.h"
#include "Game.h"

void Torpedo::move(size_t direction, size_t step){
  //can not over island
  switch(direction){
    case LEFT:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row,col-1))remove();
      }
      break;
    case RIGHT:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row,col+1))remove();
      }
      break;
  }
  //use father class move
  Weapon::move(direction,step);
  
}

void Torpedo::show(){
  game->paintAt(row, col, '=');
}

void Torpedo::check_crash(){
  Ship* tem=game->getShip(row,col);
  if(tem!=nullptr){
    tem->health-=10;
  }
}

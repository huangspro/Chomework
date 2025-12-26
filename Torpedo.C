#include "Torpedo.h"
#include "Game.h"

void Torpedo::move(size_t direction, size_t step){
  //can not over island
  switch(direction){
    case LEFT:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row,col-1)->type==Island_n)remove();
      }
      break;
    case RIGHT:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row,col+1)->type==Island_n)remove();
      }
      break;
  }
  //use father class move
  Weapon::move(direction,step);
  //check crash
  Ship* temm = game->getShip(row,col);
  if(temm!=nullptr){
    temm->health-=10;
  }
}

void Torpedo::show(){
  game->paintAt(row, col, '=');
}

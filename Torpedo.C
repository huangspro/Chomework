#include "Torpedo.h"
#include "Game.h"

void Bullet::move(size_t direction, size_t step){
  //can not over island
  switch(direction){
    case LEFT:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row,col-1)->type==Island)remove();
      }
      break;
    case RIGHT:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row,col+1)->type==Island)remove();
      }
      break;
  }
  //use father class move
  Weapon::move(direction,step);
  //check crash
  Ship* temm = game->getShip();
  if(temm!=nullptr){
    temm->health-=10;
  }
}

Bullet::show(){
  game->paintAt(row, col, '=');
}

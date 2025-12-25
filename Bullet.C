#include "Bullet.h"
#include "Game.h"

void Bullet::move(size_t direction, size_t step){
  //can not over island
  switch(direction){
    case UP:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row-i,col)->type==Island_n)remove();
      }
      break;
    case DOWN:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row+i,col)->type==Island_n)remove();
      }
      break;
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
  Ship* temm = game->getShip();
  if(temm!=nullptr){
    temm->health-=1;
  }
}

void Bullet::show(){
  game->paintAt(row, col, direction==UP|direction==DOWN?'|':'-');
}

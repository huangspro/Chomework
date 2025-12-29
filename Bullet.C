#include "Bullet.h"
#include "Game.h"

void Bullet::move(size_t direction, size_t step){
  //can not over island
  switch(direction){
    case UP:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row-i,col))remove();
      }
      break;
    case DOWN:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row+i,col))remove();
      }
      break;
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

void Bullet::show(){
  game->paintAt(row, col, direction==UP|direction==DOWN?'|':'-');
}

void Bullet::update(){
  Item::update();
}

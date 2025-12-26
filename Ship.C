#include "Ship.h"
#include "Game.h"
void Ship::move(size_t direction, size_t step){
  switch(direction){
    case UP:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row-i,col)->type==Island_n)return;
      }
      break;
    case DOWN:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row+i,col)->type==Island_n)return;
      }
      break;
    case LEFT:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row,col-1)->type==Island_n)return;
      }
      break;
    case RIGHT:
      for(int i=1;i<=step;i++){
        if(game->getIsland(row,col+1)->type==Island_n)return;
      }
      break;
  }
  Item::move(direction, step);
}

void Ship::remove(){
  game->kill(this);
}

void Ship::update(){
  Item::update();
} 

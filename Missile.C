#include "Missile.h"
#include "Game.h"

void Missile::move(size_t direction, size_t step){
  if(row <=1 || row >=MAXROW-1 || col==MAXCOL-1 || col==1)remove();
  //use father class move
  if(sender==1){
    if(game->player->row<row)direction=UP;
    else if(game->player->row>row)direction=DOWN;
    else{
      if(game->player->col<col)direction=LEFT;
      else direction=RIGHT;
    }
  }
  Weapon::move(direction,step);
}

void Missile::show(){
  game->paintAt(row, col, '*');
}

void Missile::check_crash(){
  if(t>0)return;
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

void Missile::update(){
  t--;
  Weapon::update();
  move(direction,1);
  check_crash();
}

void Missile::remove(){
  game->kill(this);
}

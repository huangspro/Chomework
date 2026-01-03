#include "Player.h"
#include "Game.h"
#include<stdlib.h>

void Player::move(size_t direction, size_t step){
  if(!(row>0 && row<MAXROW && col>0 && col<MAXCOL)){
    col=MAXCOL/2;
    row=MAXROW/2;
  }
  switch(direction){
    case UP:
      if(game->getIsland(row,col)||row==0 || row ==MAXROW || col==0 ||col==MAXCOL)row+=2;
      else row -= 1;
      break;
    case DOWN:
      if(game->getIsland(row,col)||row==0 || row ==MAXROW || col==0 ||col==MAXCOL)row-=2;
      else row += 1;
      break;
    case LEFT:
      if(game->getIsland(row,col)||row==0 || row ==MAXROW || col==0 ||col==MAXCOL)col+=2;
      else col -= 1;
      break;
    case RIGHT:
      if(game->getIsland(row,col)||row==0 || row ==MAXROW || col==0 ||col==MAXCOL)col-=2;
      else col += 1;
      break;
  }
}

void Player::show(){
  if(direction==LEFT || direction==RIGHT){
    game->paintAt(row, col-1, '<');
    game->paintAt(row, col+1, '>');    
    game->paintAt(row, col, '=');
  }
  else if(direction==UP || direction==DOWN){
    game->paintAt(row<MAXROW?row+1:row, col, 'V');
    game->paintAt(row>0?row-1:row, col, '^');
    game->paintAt(row, col, '"');
  }
}

void Player::fire(){}

void Player::fire1(int mode,int d){
  if(bullet<=0)return;
  if(mode==1){
    game->addWeapons(row, col, Bullet_n,direction, 0);
    bullet--;
  }else{
    if(direction==LEFT || direction==RIGHT){
      game->addWeapons(row, col, Bullet_n,d, 0);
      game->addWeapons(row-1, col, Bullet_n,d, 0);
      game->addWeapons(row+1, col, Bullet_n,d, 0);
      bullet-=3;
    }
  }
}
void Player::fire2(){
  if((missile)<=0)return;
  game->addWeapons(row, col, Missile_n,direction, 0);
  missile--;
}
void Player::update(){}

void Player::turn(int d){
  direction=d;
}


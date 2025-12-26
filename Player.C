#include "Player.h"
#include "Game.h"
#include<stdlib.h>

void Player::move(size_t direction, size_t step){
  Ship::move(direction, step);
}

void Player::show(){
  if(direction==UP || direction==DOWN){
    game->paintAt(row, col>0?col-1:col, '<');
    game->paintAt(row, col<MAXCOL?col+1:col, '>');    
    game->paintAt(row, col, '=');
  }
  if(direction==LEFT || direction==RIGHT){
    game->paintAt(row<MAXROW?row+1:row, col, 'V');
    game->paintAt(row>0?row-1:row, col, '^');
    game->paintAt(row, col, '"');
  }
}
/*
void Player::fire(){
  if(rand()%2==0)game->addWeapon(row, col, direction, Bullet);
  else game->addWeapon(row, col, direction, Torpedo);
}*/

void update(){
}

void Player::turn(int d){
  direction=d;
}


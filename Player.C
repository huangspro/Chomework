#include "Player.h"
#include "Game.h"
#include<stdlib.h>

void Player::move(size_t direction, size_t step){
  Ship::move(direction, step);
}

void Player::show(){
  if(direction==UP || direction==DOWN){
    game->paintAt(row, col-1, '<');
    game->paintAt(row, col+1, '>');    
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
void Player::update(){
  int temm=game->gui.get();
  switch(temm){
    case KEY_UP:
      turn(UP);
      move(UP,1);
      break;
    case KEY_DOWN:
      turn(DOWN);
      move(DOWN,1);
      break;
    case KEY_LEFT:
      turn(LEFT);
      move(LEFT,1);
      break;
    case KEY_RIGHT:
      turn(RIGHT);
      move(RIGHT,1);
      break;
  }
}

void Player::turn(int d){
  direction=d;
}


#include "Player.h"
#include "Game.h"
#include<stdlib>

void Player::move(size_t direction, size_t step){
  Ship::move(direction, step);
}

void Player::show(){
  game->paintAt(row, col, 'O');
}

void Player::fire(){
  if(rand()%2==0)game->addWeapon(row, col, direction, Bullet);
  else game->addWeapon(row, col, direction, Torpedo);
}

void update(){
  Item::update();
}

#include "WeaponPack.h"
#include "Game.h"

void WeaponPack::update(){
  Pack::update();
  check_crash();
}

void WeaponPack::remove(){
  game->kill(this);;
}

void WeaponPack::check_crash(){
  for(int i=0;i<5;i++){
    Ship* tem=game->getShips(row,col);
    if(tem!=nullptr && tem==game->player){
      tem->bullet+=20;
      tem->torpedo+=1;
      tem->missile+=1;
      remove();
    }
  }
}

void WeaponPack::show(){
  game->paintAt(row, col, 'W');
}

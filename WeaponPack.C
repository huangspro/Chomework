#include "WeaponPack.h"
#include "Game.h"
void WeaponPack::update(){
  Pack::update();
  check_crash();
}

void WeaponPack::remove(){
  game->kill(this);;
}
void WeaponPack::tem_f(Ship* i){
  if(i!=nullptr && i==game->player){
    i->bullet+=20;
    i->torpedoes+=1;
    i->missile+=1;
    remove();
  }
}
void WeaponPack::check_crash(){
  Ship* tem1=game->getShip(row,col);
  Ship* tem2=game->getShip(row-1,col);
  Ship* tem3=game->getShip(row+1,col);
  Ship* tem4=game->getShip(row,col-1);
  Ship* tem5=game->getShip(row,col+1);
  
  tem_f(tem1);
  tem_f(tem2);
  tem_f(tem3);
  tem_f(tem4);
  tem_f(tem5);
}

void WeaponPack::show(){
  game->paintAt(row, col, 'W');
}


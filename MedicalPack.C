#include "MedicalPack.h"
#include "Game.h"

void MedicalPack::update(){
  Pack::update();
  check_crash();
}

void MedicalPack::remove(){
  game->kill(this);;
}
void MedicalPack::tem_f(Ship* i){
  if(i!=nullptr && i==game->player){
    i->health+=100;
    remove();
  }
}
void MedicalPack::check_crash(){
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

void MedicalPack::show(){
  game->paintAt(row, col, 'W');
}


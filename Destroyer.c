#include "Destroyer.h"
#include "Game.h"
#include<stdlib>

void Destroyer::move(size_t direction, size_t step){
  int d[]={1,2,3,4};
  Ship::move(d[rand()%4], 1);
}

void Destroyer::show(){
  game->paintAt(row, col, 'O');
}

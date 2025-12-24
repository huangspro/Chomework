#include "Cruiser.h"
#include "Game.h"
#include<stdlib>

void Cruiser::move(size_t direction, size_t step){
  int d[]={1,2,3,4};
  Ship::move(d[rand()%4], 1);
}

void Cruiser::show(){
  game->paintAt(row, col, 'o');
}

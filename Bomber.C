#include "Bomber.h"
#include "Game.h"

//the show function maybe complex, so the bomber's position must be initialized from the 2nd line
void Bomber::show(){
  if(direction==RIGHT){
    game->paintAt(row, col, '=');
    game->paintAt(row, col-1, '=');
    game->paintAt(row-1, col, '\\');
    game->paintAt(row+1, col, '/');
  }
  else if(direction==LEFT){
    game->paintAt(row, col, '=');
    game->paintAt(row, col+1, '=');
    game->paintAt(row-1, col, '/');
    game->paintAt(row+1, col, '\\');
  }
}

void Bomber::fire(){
  
}

void Bomber::update(){
  Item::update();
  move();
}

void Bomber::move(size_t direction, size_t step){
  Item::move(direction, step);
}


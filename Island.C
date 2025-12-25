#include "Island.h"

void Island::show(){
  game->paintAt(row, col, '#');
}

void Island::update(){
  show();
}

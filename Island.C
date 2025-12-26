#include "Island.h"
#include "Island.h"
#include "Game.h"

void Island::show(){
  game->paintAt(row, col, '#');
}

void Island::update(){
  show();
}

#include "Pack.h"

void Pack::show(){
  game->paintAt(row, col, '#');
}

void Pack::update(){
  show();
}


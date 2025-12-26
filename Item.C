#include "Item.h";

Item::Item(Game* g, size_t r, size_t c,size_t v, size_t t):game(g),row(t),col(c),type(t),v(v){}

//we do not deal with island here, for some items like missile can fly over it
void Item::move(size_t direction, size_t step){
  if(tem<=v)return;
  switch(direction){
    case UP:
      row -= row==1?0:(rand() % (row - 1 < step ? row - 1 : step) + 1);
      break;
    case DOWN:
      row += row==MAXROW?0:(rand() % (MAXROW - row < step ? MAXROW - row : step) + 1);
      break;
    case LEFT:
      col -= col==1?0:(rand() % (col - 1 < step ? col - 1 : step) + 1);
      break;
    case RIGHT:
      col += col==MAXCOL?0:(rand() % (MAXCOL - col < step ? MAXCOL - col : step) + 1);
      break;
  }
  tem=0; //every time move, tem should be set 0
}

void Item::update(){
  tem++;
}

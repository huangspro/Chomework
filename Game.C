#include <cstdlib>
#include<stdlib.h>
#include <ctime>
#include <vector>
#include "Game.h"
#include <algorithm>
Game::Game()
{
    std::srand(std::time(nullptr));
    for(int i=0;i<10;i++){
      AllIslands.push_back(new Island(this,rand()%MAXROW+1,rand()%MAXCOL+1));
    }
    player = new Player(this, 0.5*MAXROW, 0.5*MAXCOL);
}

void Game::update(){
  for(auto i=AllIslands.begin();i!=AllIslands.end();i++){
    (*i)->update();
    if((*i)->showable)(*i)->show();
  }
  for(auto i=AllWeapons.begin();i!=AllWeapons.end();i++){
    (*i)->update();
    if((*i)->showable)(*i)->show();
  }
  for(auto i=AllBombers.begin();i!=AllBombers.end();i++){
    (*i)->update();
    if((*i)->showable)(*i)->show();
  }
  for(auto i=AllPacks.begin();i!=AllPacks.end();i++){
    (*i)->update();
    if((*i)->showable)(*i)->show();
  }
  addShips();
  switch(gui.get()){
    case KEY_UP:
      player->turn(UP);
      player->update();
      break;
    case KEY_DOWN:
      player->turn(DOWN);
      player->update();
      break;
    case KEY_LEFT:
      player->turn(LEFT);
      player->update();
      break;
    case KEY_RIGHT:
      player->turn(RIGHT);
      player->update();
      break;
    
  }
}

void Game::addShips(){
  size_t x=rand()%MAXROW+1;
  size_t y=rand()%MAXCOL+1;
  for(auto i=AllIslands.begin();i!=AllIslands.end();i++){
    if(x==(*i)->row && y==(*i)->col)addShips();
  }
  AllShips.push_back(new Gunboat(this, x,y));
}

void Game::kill(Item* other){
  if(other->type>=5 && other->type<=7){
    for(auto i=AllShips.begin();i!=AllShips.end();i++){
      if(other->row==(*i)->row && other->col==(*i)->col)(*i)->showable=false;
    }
  }
  else if(other->type>=1 && other->type<=3){
    for(auto i=AllWeapons.begin();i!=AllWeapons.end();i++){
      if(other->row==(*i)->row && other->col==(*i)->col)(*i)->showable=false;
    }
  }
  else if(other->type==4){
    for(auto i=AllBombers.begin();i!=AllBombers.end();i++){
      if(other->row==(*i)->row && other->col==(*i)->col)(*i)->showable=false;
    }
  }
}

Island* Game::getIsland(size_t row, size_t col){
  for(auto i=AllIslands.begin();i!=AllIslands.end();i++){
      if(row==(*i)->row && col==(*i)->col)return (*i);
  }
}
Ship* Game::getShip(size_t row, size_t col){
  for(auto i=AllShips.begin();i!=AllShips.end();i++){
      if(row==(*i)->row && col==(*i)->col)return (*i);
  }
}

void Game::addWeapons(){
  
}

void Game::paintAt(size_t r, size_t c, char x)
{
    gui.paintat(r, c, x);
}

void Game::printMsg(size_t r, size_t c, const char *s)
{
    gui.printMsg(r, c, s);
}

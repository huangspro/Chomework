#include <cstdlib>
#include <ctime>
#include <vector>
#include "Game.h"
#include "Item.h"
#include <algorithm>
Game::Game()
{
    std::srand(std::time(nullptr));
    for(int i=0;i<10;i++){
      AllIslands.push_back(new Island(this,rand()%MAXROW+1,rand()%MAXCOL+1));
    }
}

void Game::update(){
  for(auto i=AllIslands.begin();i!=AllIslands.end();i++){
    i->update();
  }
  for(auto i=AllWeapons.begin();i!=AllWeapons.end();i++){
    i->update();
  }
  for(auto i=AllBombers.begin();i!=AllBombers.end();i++){
    i->update();
  }
  for(auto i=AllPacks.begin();i!=AllPacks.end();i++){
    i->update();
  }
  addShips();
}

void addShips(){
  size_t x=rand()%MAXROW+1;
  size_t y=rand()%MAXCOL+1;
  for(auto i=AllIslands.begin();i!=AllIslands.end();i++){
    if(x==i->row && y==i->col)addShips();
  }
  AllShips.push_back(new Gunboat(this, x,y));
}

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
    printMsg(0,0,"here");
}

void Game::update(){
  clear();refresh();
  if(player->health<=0)exit(0);
  //here can clear the killed ships
  for(auto i=AllIslands.begin();i!=AllIslands.end();i++){
    if((*i)->showable)(*i)->show();
  }
  for(auto i=AllWeapons.begin();i!=AllWeapons.end();i++){
    (*i)->update();
    if((*i)->showable)(*i)->show();
  }
  for(auto i=AllShips.begin();i!=AllShips.end();i++){
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
  addBomber();
  addWeapons(5,5,Torpedo_n,RIGHT);
  addPacks();
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
    player->show();
  }
}
void Game::addPacks(){
  if(rand()%50>2)return;
  size_t x=rand()%MAXROW+1;
  size_t y=rand()%MAXCOL+1;
  //if(rand()%2==0)AllPacks.push_back(new WeaponPack(this, x,y));
  //else AllPacks.push_back(new MedicalPack(this, x,y));
}

void Game::addBomber(){
  if(rand()%50>2)return;
  size_t x=rand()%MAXROW+1;
  size_t y=rand()%MAXCOL+1;
  Bomber* newone=new Bomber(this, x,y);
  newone->direction=LEFT;
  AllBombers.push_back(newone);
}
void Game::addShips(){
  if(rand()%50>2)return;
  Ship* newone;
  size_t x=rand()%MAXROW+1;
  size_t y=rand()%MAXCOL+1;
  for(auto i=AllIslands.begin();i!=AllIslands.end();i++){
    if(x!=(*i)->row && y!=(*i)->col){
      switch(rand()%3){
        case 0:
          newone=new Gunboat(this, x,y);
          newone->direction=UP;
          AllShips.push_back(newone);break;
        case 1:
          newone=new Cruiser(this, x,y);
          newone->direction=LEFT;
          AllShips.push_back(newone);break;
        case 2:
          newone=new Destroyer(this, x,y);
          newone->direction=UP;
          AllShips.push_back(newone);break;
      }
    }
    else return;
  }
  
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

bool Game::getIsland(size_t row, size_t col){
  if(row>0 && row<=MAXROW && col>0 && col<=MAXCOL)return false;
  for(auto i=AllIslands.begin();i!=AllIslands.end();i++){
      if(row==(*i)->row && col==(*i)->col)return true;
      else return false;
  }
}
Ship* Game::getShip(size_t row, size_t col){
  for(auto i=AllShips.begin();i!=AllShips.end();i++){
      if(row==(*i)->row && col==(*i)->col)return (*i);
  }
}

void Game::addWeapons(size_t r,size_t c,int type,size_t d){
  Weapon* newone;
  switch(type){
    case Torpedo_n:
      newone=new Torpedo(this, r,c);
      newone->direction=d;
      AllWeapons.push_back(newone);break;
    case Bullet_n:
      newone=new Bullet(this, r,c);
      newone->direction=d;
      AllWeapons.push_back(newone);break;
    case Missile_n:
      newone=new Missile(this, r,c);
      newone->direction=d;
      AllWeapons.push_back(newone);break;
    }
}

void Game::paintAt(size_t r, size_t c, char x)
{
    gui.paintat(r, c, x);
}

void Game::printMsg(size_t r, size_t c, const char *s)
{
    gui.printMsg(r, c, s);
}

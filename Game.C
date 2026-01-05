#include <cstdlib>
#include<stdlib.h>
#include <ctime>
#include <vector>
#include "Game.h"
#include <algorithm>
#include<fstream>
Game::Game()
{   
    std::vector<int> coords(100);
    std::ifstream f("map/battle_islands.bin", std::ios::binary);
    if (f) {
        f.read(reinterpret_cast<char*>(coords.data()), 100 * sizeof(int));
        f.close();
    }
    
    std::srand(std::time(nullptr));
    for(int i=0;i<50;i+=2){
      AllIslands.push_back(new Island(this,coords[i],coords[i+1]));
      //AllIslands.push_back(new Island(this,rand()%MAXROW,rand()%MAXCOL));
    }
    player = new Player(this, 0.5*MAXROW, 0.5*MAXCOL);
    player->direction=UP;
    player->showable=true;
    player->show();
    refresh();
}

void Game::addPacks(){
  if(rand()%400>5-level)return;
  size_t x=rand()%MAXROW+1;
  size_t y=rand()%MAXCOL+1;
  for(auto i=0;i<AllIslands.size();i++){
      if(x==AllIslands[i]->row && y==AllIslands[i]->col)return;
  }
  if(rand()%2==0)AllPacks.push_back(new WeaponPack(this, x,y));
  else AllPacks.push_back(new MedicalPack(this, x,y));
}

void Game::addBomber(){
  if(rand()%200>2*level*level*level)return;
  size_t x=rand()%MAXROW+1;
  size_t y=rand()%MAXCOL+1;
  Bomber* newone=new Bomber(this, x,y);
  newone->direction=LEFT;
  AllBombers.push_back(newone);
}
void Game::addShips(){
  if(rand()%100>2*level*level*level)return;
  Ship* newone;
  size_t x=rand()%MAXROW+1;
  size_t y=rand()%MAXCOL+1;
  for(auto i=AllIslands.begin();i!=AllIslands.end();i++){
    if(x==(*i)->row && y==(*i)->col)return;
  }
  switch(rand()%3){
    case 0:
      newone=new Gunboat(this, x,y);
      newone->direction=UP;
      AllShips.push_back(newone);return;
    case 1:
      newone=new Cruiser(this, x,y);
      newone->direction=LEFT;
      AllShips.push_back(newone);return;
    case 2:
      newone=new Destroyer(this, x,y);
      newone->direction=UP;
      AllShips.push_back(newone);return;
  }
  
}

void Game::kill(Item* other){
  player->coins+=other->type==Destroyer_n?1:(other->type==Cruiser_n?10:0);
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
  else if(other->type==WeaponPack_n || other->type==MedicalPack_n){
    for(auto i=AllPacks.begin();i!=AllPacks.end();i++){
      if(other->row==(*i)->row && other->col==(*i)->col)(*i)->showable=false;
    }
  }
}

bool Game::getIsland(size_t row, size_t col){
  for(auto i=0;i<AllIslands.size();i++){
      if(row==AllIslands[i]->row && col==AllIslands[i]->col)return true;
  }
  return false;
}

Ship* Game::getShip(size_t row, size_t col){
  if(player->row==row && player->col==col)return player;
  for(int i=0;i<AllShips.size();i++){
      if(row==AllShips[i]->row && col==AllShips[i]->col)return AllShips[i];
  }
  return nullptr;
}

void Game::addWeapons(size_t r,size_t c,int type,size_t d, int sender){
  if(r<0 || r >MAXROW || c <0 || c>MAXCOL)return;
  Weapon* newone;
  switch(type){
    case Torpedo_n:
      newone=new Torpedo(this, r,c,sender);
      newone->direction=d;
      AllWeapons.push_back(newone);break;
    case Bullet_n:
      newone=new Bullet(this, r,c,sender);
      newone->direction=d;
      AllWeapons.push_back(newone);break;
    case Missile_n:
      newone=new Missile(this, r,c,sender);
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
void Game::printMsg(size_t r, size_t c, size_t s)
{
    char tem[10];
    snprintf(tem,sizeof(s),"%zu",s);
    gui.printMsg(r, c, tem);
}


void Game::update(){
  tem++;
  if(tem%10==0)player->bullet+=1;
  else if(tem%1000==0)player->missile+=5;
  erase();
  if(player->coins>=10){
    player->coins=0;
    level++;
  }
  
  attron(COLOR_PAIR(1));
  printMsg(0,MAXCOL+1,"coins: ");
  printMsg(0,MAXCOL+1+7,player->coins);
  printMsg(1,MAXCOL+1,"health: ");
  printMsg(1,MAXCOL+1+7,player->health);
  printMsg(2,MAXCOL+1,"bullet: ");
  printMsg(2,MAXCOL+1+8,player->bullet);
  printMsg(3,MAXCOL+1,"missile: ");
  printMsg(3,MAXCOL+1+9,player->missile);
  printMsg(4,MAXCOL+1,"torpedo: ");
  printMsg(4,MAXCOL+1+9,player->torpedoes);
  printMsg(5,MAXCOL+1,"level: ");
  printMsg(5,MAXCOL+1+7,level);
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(2));

  //here can clear the killed ships
  attron(COLOR_PAIR(5));
  for (int i = 0; i < AllIslands.size(); ++i){
    if (AllIslands[i]->showable) AllIslands[i]->show();
  }
  attroff(COLOR_PAIR(5));
  attron(COLOR_PAIR(6));
  for (int i = 0; i < AllWeapons.size(); ++i) {
    if (!AllWeapons[i]->showable) { delete AllWeapons[i]; AllWeapons.erase(AllWeapons.begin() + i); i--; continue; }
    AllWeapons[i]->update();
    AllWeapons[i]->show();
  }
  attroff(COLOR_PAIR(6));
  attron(COLOR_PAIR(2));
  for (int i = 0; i < AllShips.size(); ++i) {
    if (!AllShips[i]->showable) { delete AllShips[i]; AllShips.erase(AllShips.begin() + i); break;}
    AllShips[i]->update();
    if (AllShips[i]->health <= 0) kill(AllShips[i]);
    if (AllShips[i]->showable) AllShips[i]->show();
  }
  for (int i = 0; i < AllBombers.size(); ++i) {
    if (!AllBombers[i]->showable) { delete AllBombers[i]; AllBombers.erase(AllBombers.begin() + i); i--; continue; }
    AllBombers[i]->update();
    if (AllBombers[i]->showable) AllBombers[i]->show();
  }  
  attroff(COLOR_PAIR(2));
  attron(COLOR_PAIR(4));
  for (int i = 0; i < AllPacks.size(); ++i) {
    if (!AllPacks[i]->showable) { delete AllPacks[i]; AllPacks.erase(AllPacks.begin() + i); i--; continue; }
    AllPacks[i]->update();
    if (AllPacks[i]->showable) AllPacks[i]->show();
  }
  attroff(COLOR_PAIR(4));
  addShips();
  addBomber();
  addPacks();
  
  int temm=gui.get();
  switch(temm){
    case KEY_UP:
      player->turn(UP);
      player->move(UP,1);
      break;
    case KEY_DOWN:
      player->turn(DOWN);
      player->move(DOWN,1);
      break;
    case KEY_LEFT:
      player->turn(LEFT);
      player->move(LEFT,1);
      break;
    case KEY_RIGHT:
      player->turn(RIGHT);
      player->move(RIGHT,1);
      break;
    case ' ':
      player->fire1(1,0);break;
    case 'a':
      player->fire1(0,LEFT);break;
    case 'd':
      player->fire1(0,RIGHT);break;
    case 'm':
      player->fire2();break;
    case 't':
      player->fire3();break;
  }
  player->show();
  refresh();
  if(player->health<=0)exit(0);
}

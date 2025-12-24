#include <cstdlib>
#include <ctime>
#include <vector>
#include "Tiger.h"
#include "Wolf.h"
#include "Rabbit.h"
#include "Grass.h"
#include "Game.h"
#include <algorithm>
Game::Game(int rab, int pre)
{
    // 初始化随机数种子
    std::srand(std::time(nullptr));

    // 保留原逻辑：行列从1开始
    for (int i = 1; i <= MAXROW; i++)
    {
        for (int ii = 1; ii <= MAXCOL; ii++)
        {
            G.push_back(new Grass(this, i, ii));
        }
    }
    for (int i = 1; i <= rab; i++)
    {
        add(new Rabbit(this, rand() % MAXROW+1, rand() % MAXCOL+1));
    }
    for (int i = 1; i <= pre; i++)
    {
        if(rand()%2==0)A.push_back(new Tiger(this, rand() % MAXROW+1, rand() % MAXCOL+1));
        else A.push_back(new Wolf(this, rand() % MAXROW+1, rand() % MAXCOL+1));
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

void Game::kill(Animal *other)
{
    other->life=0;
    other->row=0;
    other->col=0;
}

Animal *Game::pick(int type, int r, int c, int range)
{
    for (auto it = A.begin(); it != A.end(); it++)
    {
        if (((*it)->row == r && (*it)->col >= c - range && (*it)->col <= c + range && (*it)->col != c) ||
            ((*it)->col == c && (*it)->row >= r - range && (*it)->row <= r + range && (*it)->row != r))
        {
            if ((*it)->type == type)
            {
                return *it;
            }
        }
    }
    return nullptr;
}

Grass *Game::pick_grass(int r, int c)
{
    return G[MAXCOL * (r - 1) + c - 1];
}

void Game::update()
{
    switch (gui.get())
    {
    case 'a':
        if (rand() % 2 == 0)
            add(new Tiger(this, rand() % MAXROW+1, rand() % MAXCOL+1));
        else
            add(new Wolf(this, rand() % MAXROW+1, rand() % MAXCOL+1));
        break;
    case 'd':
        add(new Rabbit(this, rand() % MAXROW+1, rand() % MAXCOL+1));
        break;
    case 'q':
        exit(0);
    }

    updateItems();
}

void Game::updateItems()
{
    // 遍历G，保留原逻辑
    for (auto it = G.begin(); it != G.end(); it++)
    {
        (*it)->grow();
        (*it)->draw();
    }
    // 遍历A，保留原逻辑
    for (auto it = A.begin(); it != A.end(); it++)
    {
        if((*it)->life==0)continue;
        (*it)->update();
        (*it)->draw();
    }
}

void Game::add(Animal* other)
{
    for (auto a : A)
    {
        if (a->row == other->row &&
            a->col == other->col)
        {
            return;
        }
    }
    A.push_back(other);
}

Game::~Game(){
    for (auto a : A){
        delete a;
    }
    for (auto a : G){
        delete a;
    }
    gui.end();
}
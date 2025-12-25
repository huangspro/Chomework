#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player : public Ship{
public:
  size_t coins = 0;
  Player(Game* g, size_t r, size_t c):Ship(g,r,c,Player_v,Player_n){
    health=1000;
    bullet=100;
    missile=5;
    torpedoes=0;
  }
  void move(size_t direction, size_t step);
  void show();
  void fire();
  void update();
  void turn(int);
};

#endif

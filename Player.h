#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player : public Ship{
public:
  Player(Game* g, size_t r, size_t c):Ship(g,r,c,Player_v,Player){
    health=10;
    bullet=10;
    missile=0;
    torpedoes=2;
  }
  void move(size_t direction, size_t step);
  void show();
  void fire();
  void update();
};

#endif

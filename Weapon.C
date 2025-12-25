#include "Weapon.h"
#include "Game.h"

void Weapon::remove(){
  game->kill(this);
}

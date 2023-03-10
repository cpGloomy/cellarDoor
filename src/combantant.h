#ifndef COMBANTANT_H
#define COMBANTANT_H

#include "log.h"
#include "mobiles.h"
#include "randomnumbers.h"

class Combantant {
 public:
  Combantant(){};
  Combantant(Mobiles *self) : self_(self), target_(nullptr) {}
  ~Combantant(){};

  bool SetTarget(Mobiles *target);
  bool DoAttack();

  Mobiles *self_;
  Mobiles *target_;

 private:
  bool IsHit();
  int RollDamage();
  bool DealDamage(int dmg);
  float CalculateHitChance();
};

#endif  //? COMBANTANT_H
#ifndef COMBANTANT_H
#define COMBANTANT_H

#include "mobiles.h"
#include "randomnumbers.h"

class Combantant {
 public:
  Combantant(){};
  Combantant(Mobiles* self) : self_(self), target_(nullptr) {}
  ~Combantant(){};

  void SetTarget(Mobiles* target) { target_ = target; }
  bool DoAttack();
  bool IsHit();
  int RollDamage();
  bool DealDamage(int dmg);

  Mobiles* self_;
  Mobiles* target_;
};

#endif  //? COMBANTANT_H
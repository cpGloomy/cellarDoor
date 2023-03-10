#ifndef COMBAT_H
#define COMBAT_H

#include "combantant.h"

class Combat {
 public:
  Combat(){};
  ~Combat(){};

  void AddCombantant(Combantant* c);
  void DoAttackRound();

 private:
  bool DoAfterRoundCleanup();
  bool AssignTarget(Combantant* c);
  bool CombantantAttacks(Combantant* c);

  std::vector<Combantant*> combantants_;
};

#endif  //? COMBAT_H
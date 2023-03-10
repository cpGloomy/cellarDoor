#include "combat.h"

void Combat::AddCombantant(Combantant* c) { combantants_.push_back(c); }

void Combat::DoAttackRound() {
  for (Combantant* c : combantants_) {
    if (c->self_->IsAlive()) {
      c->DoAttack();
    }
  }
  DoAfterRoundCleanup();
}

bool Combat::DoAfterRoundCleanup() {
  for (Combantant* c : combantants_) {
    if (!c->self_->IsAlive() && c->self_->IsPlayer()) return false;
    if (c->self_->IsAlive() && !c->target_->IsAlive())
      if (!AssignTarget(c)) return false;
  }
  return true;
}

bool Combat::AssignTarget(Combantant* cc) {
  for (Combantant* c : combantants_) {
    if (c->self_->IsAlive() && c != cc &&
        c->self_->IsAlly() != cc->self_->IsAlly()) {
      cc->SetTarget(c->self_);
      return true;
    }
  }
  return false;
}
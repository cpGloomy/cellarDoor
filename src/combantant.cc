#include "combantant.h"

#include <iostream>
#include <string>

bool Combantant::SetTarget(Mobiles *target) {
  if (!target->IsAlive())
    return false;
  else {
    target_ = target;
    return true;
  }
}

bool Combantant::DoAttack() {
  if (!self_->IsAlive()) {
    LOG_WARN("DoAttack Comantant {0} alive= {1}", self_->GetName(),
             self_->IsAlive());
    return false;
  } else if (!target_->IsAlive()) {
    LOG_WARN("DoAttack Target {0} alive= {1}", target_->GetName(),
             target_->IsAlive());
    return false;
  }

  if (IsHit()) {
    int dmg = RollDamage();
    DealDamage(dmg);
    LOG_INFO("{0} attacks {1} for {2} damage!", self_->GetName(),
             target_->GetName(), dmg);
  } else {
    LOG_INFO("{0} misses {1}!", self_->GetName(), target_->GetName());
  }

  return true;
}

bool Combantant::IsHit() { return true; }

int Combantant::RollDamage() {
  int min = self_->GetStats(STATS::minDamage);
  int max = self_->GetStats(STATS::maxDamage);
  int dmg = RandomNumbers::GetInstance()->Roll(min, max);
  LOG_INFO("Damage rolled: {0} :: min {1} max {2}", dmg, min, max);
  return dmg;
}

bool Combantant::DealDamage(int dmg) {
  int cHP = target_->GetStats(STATS::currentHP);
  int newHP = cHP - dmg;
  target_->SetStats(STATS::currentHP, newHP);
  LOG_INFO("{0} took {1} damage :: currentHP {2} newHP {3}", target_->GetName(),
           dmg, cHP, newHP);
  if (newHP <= 0) {
    LOG_INFO("{0} is now dead alive={1}", target_->GetName(),
             target_->IsAlive());
    target_->SetAlive(false);
  }
  return true;
}
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
  // Check if self or target is alive, returns false for dead.
  if (!self_->IsAlive()) {
    LOG_WARN("DoAttack Comantant {0} alive= {1}", self_->GetName(),
             self_->IsAlive());
    return false;
  } else if (!target_->IsAlive()) {
    LOG_WARN("DoAttack Target {0} alive= {1}", target_->GetName(),
             target_->IsAlive());
    return false;
  }

  // Roll for Hit
  if (IsHit()) {
    int dmg = RollDamage();
    DealDamage(dmg);
    LOG_INFO("{0} attacks {1} for {2} damage!", self_->GetName(),
             target_->GetName(), dmg);
  } else {
    LOG_DEBUG("{0} misses {1}!", self_->GetName(), target_->GetName());
  }

  return true;
}

// if chance_to_hit >= probability
bool Combantant::IsHit() {
  float chance_to_hit = CalculateHitChance();
  int probability = RandomNumbers::GetInstance()->Roll(0, 100);
  chance_to_hit = chance_to_hit * 100;

  LOG_DEBUG("chance_to_hit {0} probability {1}", chance_to_hit, probability);
  if (chance_to_hit >= probability) {
    LOG_DEBUG("Hit!");
    return true;
  } else {
    LOG_DEBUG("Miss!");
    return false;
  }
}

int Combantant::RollDamage() {
  int min = self_->GetStats(STATS::minDamage);
  int max = self_->GetStats(STATS::maxDamage);
  int dmg = RandomNumbers::GetInstance()->Roll(min, max);
  LOG_DEBUG("Damage rolled: {0} :: min {1} max {2}", dmg, min, max);
  return dmg;
}

bool Combantant::DealDamage(int dmg) {
  int cHP = target_->GetStats(STATS::currentHP);
  int newHP = cHP - dmg;
  target_->SetStats(STATS::currentHP, newHP);
  LOG_DEBUG("{0} took {1} damage :: currentHP {2} newHP {3}",
            target_->GetName(), dmg, cHP, newHP);
  if (newHP <= 0) {
    LOG_INFO("{0} is now dead alive={1}", target_->GetName(),
             target_->IsAlive());
    target_->SetAlive(false);
  }
  return true;
}

//* returns a float probability 0 - 1
//* odds are calculated thus:
//* chance_to_hit = (self_::weapon_skill_) + (self_::accuracy_) /
//* (self_::weapon_skill_) + (target_::evasion)
float Combantant::CalculateHitChance() {
  int ws = self_->GetStats(STATS::weaponSkill);
  int acc = self_->GetStats(STATS::accuracy);
  int eva = target_->GetStats(STATS::evasion);
  int numerator = (ws + acc);
  int demoniator = ((ws + eva) <= 0) ? 1 : (ws + eva);
  float chance_to_hit =
      (static_cast<float>(numerator) / static_cast<float>(demoniator));

  LOG_DEBUG("ws={0} acc={1} eva={2} change_to_hit={3}", ws, acc, eva,
            chance_to_hit);
  return chance_to_hit;
}
#include "combantant.h"

#include <iostream>
#include <string>

bool Combantant::DoAttack() {
  std::cout << "Combantant::DoAttack self=" << self_->GetName()
            << " alive=" << self_->IsAlive() << " target=" << target_->GetName()
            << " alive=" << target_->IsAlive() << std::endl;

  if (!self_->IsAlive() || !target_->IsAlive()) return false;
  std::string showAtk = self_->GetName();

  if (IsHit()) {
    int dmg = RollDamage();
    DealDamage(dmg);
    std::cout << self_->GetName() << " attacks " << target_->GetName()
              << " for " << dmg << " damage!" << std::endl;
  } else {
    std::cout << self_->GetName() << " misses " << target_->GetName() << "!"
              << std::endl;
  }

  return true;
}

bool Combantant::IsHit() { return true; }

int Combantant::RollDamage() { return 10; }

bool Combantant::DealDamage(int dmg) {
  int cHP = target_->GetStats(STATS::currentHP);
  int newHP = cHP - dmg;
  target_->SetStats(STATS::currentHP, newHP);
  std::cout << "Combantant::DealDamage dmg=" << dmg << " currentHP=" << cHP
            << " newHP = " << newHP << std::endl;
  if (newHP <= 0) {
    self_->SetAlive(false);
  }
  return true;
}
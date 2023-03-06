#include "monster.h"

Monster::Monster(MonsterType *type) {
  this->type = type;
  this->SetName(this->type->GetName());
}

GiantRat::GiantRat() {
  this->baseStats = new MobilesBaseStats;
  this->baseStats->maxHP = 45;
  this->baseStats->currentHP = 45;
}
#include "monster.h"

Monster::Monster() {
  type = new MonsterType("null", 0, 0, 0);
  stats = new MobilesStatSheet(0, 0, 0);
}

Monster::Monster(MonsterType* type) {
  this->type = type;
  this->SetName(this->type->name);

  this->stats = new MobilesStatSheet(
      this->type->baseHP, this->type->startingLevel, this->type->startingExps);
  this->stats->currentHP = this->type->baseHP;
  this->stats->maxHP = this->type->baseHP;

  this->stats->currentHP = this->type->baseHP;
  this->stats->level = this->type->startingLevel;
  this->stats->experience = this->type->startingExps;
}

Monster::~Monster() {
  delete type;
  delete stats;
}
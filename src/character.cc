#include "character.h"

#include <iostream>

Character::Character() { this->stats = new MobilesStatSheet(0, 0, 0); }

Character::~Character() { delete this->stats; }

int Character::GetStats(STATS stat) {
  switch (stat) {
    case STATS::maxHP:
      return this->stats->maxHP;
    case STATS::currentHP:
      return this->stats->currentHP;
    case STATS::level:
      return this->stats->level;
    case STATS::experience:
      return this->stats->experience;
    default:
      return 0;
  }
}

void Character::SetStats(STATS stat, int value) {
  switch (stat) {
    case STATS::maxHP:
      stats->maxHP = value;
    case STATS::currentHP:
      stats->currentHP = value;
    case STATS::level:
      stats->level = value;
    case STATS::experience:
      stats->experience = value;
  }
}
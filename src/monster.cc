#include "monster.h"

Monster::Monster() {
  type = new MobilesType("null", 0, 0, 0);
  stats = new MobilesStatSheet(0, 0, 0, 0, 0);
}

Monster::Monster(MobilesType *type) {
  this->type = type;
  this->SetName(this->type->GetName());

  stats = new MobilesStatSheet(this->type->GetHP(), this->type->GetLevel(),
                               this->type->GetExp(), 1, 5);
}

Monster::~Monster() {
  delete type;
  delete stats;
}

int Monster::GetStats(STATS stat) {
  switch (stat) {
    case MobilesStatSheet::Stats::maxHP:
      return stats->maxHP;
    case MobilesStatSheet::Stats::currentHP:
      return stats->currentHP;
    case MobilesStatSheet::Stats::level:
      return stats->level;
    case MobilesStatSheet::Stats::experience:
      return stats->experience;
    case STATS::minDamage:
      return stats->minDamage;
    case STATS::maxDamage:
      return stats->maxDamage;
    default:
      return 0;
  }
}

void Monster::SetStats(STATS stat, int value) {
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
#include "monster.h"

Monster::Monster() {
  type = new MobilesType("null", 0, 0, 0, 0, 0, 0, 0, 0);
  stats = new MobilesStatSheet(0, 0, 0, 0, 0, 0, 0, 0);
}

Monster::Monster(MobilesType *type) {
  this->type = type;
  this->SetName(this->type->GetName());

  stats = new MobilesStatSheet(
      this->type->GetHP(), this->type->GetLevel(), this->type->GetExp(),
      this->type->GetMinDamage(), this->type->GetMaxDamage(),
      this->type->GetWeaponSkill(), this->type->GetAccuracy(),
      this->type->GetEvasion());
}

Monster::~Monster() {
  delete type;
  delete stats;
}

int Monster::GetStats(STATS stat) {
  switch (stat) {
    case STATS::maxHP:
      return stats->maxHP;
    case STATS::currentHP:
      return stats->currentHP;
    case STATS::level:
      return stats->level;
    case STATS::experience:
      return stats->experience;
    case STATS::minDamage:
      return stats->minDamage;
    case STATS::maxDamage:
      return stats->maxDamage;
    case STATS::weaponSkill:
      return stats->weapon_skill_;
    case STATS::accuracy:
      return stats->accuracy_;
    case STATS::evasion:
      return stats->evasion_;
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
    case STATS::minDamage:
      stats->minDamage = value;
    case STATS::maxDamage:
      stats->maxDamage = value;
    case STATS::weaponSkill:
      stats->weapon_skill_ = value;
    case STATS::accuracy:
      stats->accuracy_ = value;
    case STATS::evasion:
      stats->evasion_ = value;
  }
}
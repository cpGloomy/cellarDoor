#include "character.h"

Character::Character() { this->stats = new MobilesStatSheet(0, 0, 0); }

Character::~Character() { delete this->stats; }

int Character::GetStats(MobilesStatSheet::Stats stat) {
  switch (stat) {
    case MobilesStatSheet::Stats::maxHP:
      return this->stats->maxHP;
    case MobilesStatSheet::Stats::currentHP:
      return this->stats->currentHP;
    case MobilesStatSheet::Stats::level:
      return this->stats->level;
    case MobilesStatSheet::Stats::experience:
      return this->stats->experience;
    default:
      return 0;
  }
}
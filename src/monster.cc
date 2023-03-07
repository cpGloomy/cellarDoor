#include "monster.h"

Monster::Monster() {
  type = new MobilesType("null", 0, 0, 0);
  stats = new MobilesStatSheet(0, 0, 0);
}

Monster::Monster(MobilesType* type) {
  this->type = type;
  this->SetName(this->type->name);

  this->stats = new MobilesStatSheet(std::stoi(this->type->baseHP),
                                     std::stoi(this->type->startingLevel),
                                     std::stoi(this->type->startingExps));
}

Monster::~Monster() {
  delete type;
  delete stats;
}

int Monster::GetStats(MobilesStatSheet::Stats stat) {
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
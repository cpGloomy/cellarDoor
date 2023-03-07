#include "minion.h"

Minion::Minion() {
  type = new MinionType("null", 0, 0, 0);
  stats = new MobilesStatSheet(0, 0, 0);
}

Minion::Minion(MinionType* type) {
  this->type = type;
  this->SetName(this->type->name);

  this->stats = new MobilesStatSheet(std::stoi(this->type->baseHP),
                                     std::stoi(this->type->startingLevel),
                                     std::stoi(this->type->startingExps));
}

Minion::~Minion() {
  delete type;
  delete stats;
}

int Minion::GetStats(MobilesStatSheet::Stats stat) {
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
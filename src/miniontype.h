#ifndef MINIONTYPE_H
#define MINIONTYPE_H

#include <string>

struct MinionType {
  std::string name;
  int baseHP;
  int startingLevel;
  int startingExps;
  MinionType(std::string name, int hp, int lvl, int exps)
      : name(name), baseHP(hp), startingLevel(lvl), startingExps(exps){};
};

#endif  //? MINIONTYPE_H
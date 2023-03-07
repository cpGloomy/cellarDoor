#ifndef MONSTERTYPE_H
#define MONSTERTYPE_H

#include <string>

struct MonsterType {
  std::string name;
  int baseHP;
  int startingLevel;
  int startingExps;
  MonsterType(std::string name, int hp, int lvl, int exps)
      : name(name), baseHP(hp), startingLevel(lvl), startingExps(exps){};
};

#endif  //? MONSTERTYPE_H
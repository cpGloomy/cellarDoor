#ifndef MONSTER_H
#define MONSTER_H

#include <string>

#include "mobiles.h"
#include "mobilesStats.h"

struct MonsterType {
  std::string name;
  int baseHP;
  int startingLevel;
  int startingExps;
  MonsterType(std::string name, int hp, int lvl, int exps)
      : name(name), baseHP(hp), startingLevel(lvl), startingExps(exps){};
};

class Monster : public Mobiles {
 public:
  Monster();
  Monster(MonsterType* type);
  ~Monster();

  virtual std::string const GetName() { return this->name; }
  void SetName(std::string name) { this->name = name; }

  bool IsAlive() { return isAlive; }

 private:
  std::string name;
  bool isAlive = true;
  MonsterType* type;
  MobilesStatSheet* stats;
};

#endif  //? MONSTER_H
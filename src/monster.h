#ifndef MONSTER_H
#define MONSTER_H

#include <string>

#include "mobiles.h"
#include "mobilesStats.h"
#include "monstertype.h"

class Monster : public Mobiles {
 public:
  Monster();
  Monster(MonsterType* type);
  ~Monster();

  virtual std::string const GetName() { return this->name; }
  void SetName(std::string name) { this->name = name; }

  bool IsAlive() { return isAlive; }
  bool IsAlly() { return isAlly; }

  virtual int GetStats(MobilesStatSheet::Stats stat);

 private:
  std::string name;
  bool isAlive = true;
  bool isAlly = false;
  MonsterType* type;
  MobilesStatSheet* stats;
};

#endif  //? MONSTER_H
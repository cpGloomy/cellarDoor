#ifndef MONSTER_H
#define MONSTER_H

#include <string>

#include "mobiles.h"
#include "mobilesStats.h"

class MonsterType {
 public:
  MonsterType(){};
  virtual ~MonsterType() = default;

  virtual std::string const GetName() = 0;
  virtual MobilesBaseStats* GetBaseStats() = 0;
};

class GiantRat : public MonsterType {
 public:
  GiantRat();
  virtual std::string const GetName() { return this->name; }
  virtual MobilesBaseStats* GetBaseStats() { return this->baseStats; }

 private:
  std::string const name = "Giant Rat";
  MobilesBaseStats* baseStats;
};
class Monster : public Mobiles {
 public:
  Monster(){};
  Monster(std::string name) : name(name){};
  Monster(MonsterType* type);

  virtual std::string const GetName() { return this->name; }
  void SetName(std::string name) { this->name = name; }

  bool IsAlive() { return isAlive; }

 private:
  std::string name;
  bool isAlive = true;
  MonsterType* type;
};

#endif  //? MONSTER_H
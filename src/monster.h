#ifndef MONSTER_H
#define MONSTER_H

#include <string>

#include "mobiles.h"
#include "mobilesstatsheet.h"
#include "mobilestype.h"

class Monster : public Mobiles {
 public:
  Monster();
  Monster(MobilesType *type);
  ~Monster();

  virtual std::string const GetName() { return this->name; }
  void SetName(std::string name) { this->name = name; }

  virtual bool IsAlive() { return isAlive; }
  virtual bool IsAlly() { return isAlly; }
  virtual bool IsPlayer() { return is_player_; }
  virtual void SetAlive(bool alive) { isAlive = alive; }

  virtual int GetStats(STATS stat);
  virtual void SetStats(STATS stat, int value);

 private:
  std::string name;
  bool isAlive = true;
  bool isAlly = false;
  bool is_player_ = false;
  MobilesType *type;
  MobilesStatSheet *stats;
};

#endif  //? MONSTER_H
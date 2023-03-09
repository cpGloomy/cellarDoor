#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "mobiles.h"
#include "mobilesstatsheet.h"
class Character : public Mobiles {
 public:
  Character();
  Character(std::string name, MobilesStatSheet* stats)
      : name(name), stats(stats){};

  ~Character();

  std::string const GetName() { return name; }
  void SetName(std::string name) { name = name; }

  virtual bool IsAlive() { return isAlive; }
  virtual bool IsAlly() { return isAlly; }
  virtual void SetAlive(bool alive) { isAlive = alive; }

  virtual int GetStats(STATS stat);
  virtual void SetStats(STATS stat, int value);

 private:
  std::string name;
  bool isAlive = true;
  bool isAlly = true;
  MobilesStatSheet* stats;
};

#endif  //? CHARACTER_H
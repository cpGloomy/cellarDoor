#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "mobiles.h"
#include "mobilesStats.h"
class Character : public Mobiles {
 public:
  Character();
  Character(std::string name, MobilesStatSheet* stats)
      : name(name), stats(stats){};

  ~Character();

  std::string const GetName() { return name; }
  void SetName(std::string name) { name = name; }

  bool IsAlive() { return isAlive; }
  bool IsAlly() { return isAlly; }

  virtual int GetStats(
      MobilesStatSheet::Stats stat);  //! 0, maxHP, currentHP, level, experience

 private:
  std::string name;
  bool isAlive = true;
  bool isAlly = true;
  MobilesStatSheet* stats;
};

#endif  //? CHARACTER_H
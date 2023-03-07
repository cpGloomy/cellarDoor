#ifndef MINION_H
#define MINION_H

#include <string>

#include "mobiles.h"
#include "mobilesstatsheet.h"
#include "mobilestype.h"

class Minion : public Mobiles {
 public:
  Minion();
  Minion(MobilesType* type);
  ~Minion();

  virtual std::string const GetName() { return this->name; }
  void SetName(std::string name) { this->name = name; }

  bool IsAlive() { return isAlive; }
  bool IsAlly() { return isAlly; }

  virtual int GetStats(MobilesStatSheet::Stats stat);

 private:
  std::string name;
  bool isAlive = true;
  bool isAlly = true;
  MobilesType* type;
  MobilesStatSheet* stats;
};

#endif  //? MINION_H
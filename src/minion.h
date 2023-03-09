#ifndef MINION_H
#define MINION_H

#include <string>

#include "mobiles.h"
#include "mobilesstatsheet.h"
#include "mobilestype.h"

class Minion : public Mobiles {
 public:
  Minion();
  Minion(MobilesType *type);
  ~Minion();

  virtual std::string const GetName() { return this->name; }
  void SetName(std::string name) { this->name = name; }

  virtual bool IsAlive() { return isAlive; }
  virtual bool IsAlly() { return isAlly; }
  virtual void SetAlive(bool alive) { isAlive = alive; }

  virtual int GetStats(STATS stat);
  virtual void SetStats(STATS stat, int value);

 private:
  std::string name;
  bool isAlive = true;
  bool isAlly = true;
  MobilesType *type;
  MobilesStatSheet *stats;
};

#endif  //? MINION_H
#ifndef MOBILE_H
#define MOBILE_H

#include <string>

#include "mobilesstatsheet.h"

#define STATS MobilesStatSheet::Stats
class Mobiles {
 public:
  Mobiles(){};

  virtual ~Mobiles() = default;

  virtual std::string const GetName() = 0;
  virtual void SetName(std::string name) = 0;
  virtual bool IsAlive() = 0;
  virtual bool IsAlly() = 0;
  virtual void SetAlive(bool alive) = 0;

  virtual int GetStats(STATS stat) = 0;
  virtual void SetStats(STATS stat, int value) = 0;
};

#endif
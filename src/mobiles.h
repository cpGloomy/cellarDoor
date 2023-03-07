#ifndef MOBILE_H
#define MOBILE_H

#include <string>

#include "mobilesStats.h"
class Mobiles {
 public:
  Mobiles(){};

  virtual ~Mobiles() = default;

  virtual std::string const GetName() = 0;
  virtual void SetName(std::string name) = 0;
  virtual bool IsAlive() = 0;
  virtual bool IsAlly() = 0;
  virtual int GetStats(MobilesStatSheet::Stats stat) = 0;
};

#endif
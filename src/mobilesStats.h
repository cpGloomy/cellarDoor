#ifndef MOBILESSTATS_H
#define MOBILESSTATS_H

#include <string>

struct MobilesBaseStats {
  int maxHP;
  int currentHP;
};

struct MobilesStatSheet {
  int maxHP;
  int currentHP;
  int level;
  int experience;
  MobilesStatSheet(int hp, int lvl, int exp)
      : maxHP(hp), currentHP(hp), level(lvl), experience(exp){};
};
#endif  //? MOBILESSTATS_H
#ifndef MOBILESSTATS_H
#define MOBILESSTATS_H

#include <string>

struct MobilesStatSheet {
  enum class Stats {
    maxHP,
    currentHP,
    level,
    experience,
    minDamage,
    maxDamage
  };
  int maxHP;
  int currentHP;
  int level;
  int experience;
  int minDamage;
  int maxDamage;

  MobilesStatSheet(int hp, int lvl, int exp, int minDmg, int maxDmg)
      : maxHP(hp),
        currentHP(hp),
        level(lvl),
        experience(exp),
        minDamage(minDmg),
        maxDamage(maxDmg) {}
};
#endif  //? MOBILESSTATS_H
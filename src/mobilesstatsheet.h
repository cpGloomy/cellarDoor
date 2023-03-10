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
    maxDamage,
    weaponSkill,
    accuracy,
    evasion
  };

  int maxHP;
  int currentHP;
  int level;
  int experience;
  int minDamage;
  int maxDamage;
  int weapon_skill_;
  int accuracy_;
  int evasion_;

  MobilesStatSheet(int hp, int lvl, int exp, int minDmg, int maxDmg, int ws,
                   int acc, int eva)
      : maxHP(hp),
        currentHP(hp),
        level(lvl),
        experience(exp),
        minDamage(minDmg),
        maxDamage(maxDmg),
        weapon_skill_(ws),
        accuracy_(acc),
        evasion_(eva) {}
};
#endif  //? MOBILESSTATS_H
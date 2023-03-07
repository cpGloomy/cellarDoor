#ifndef MINIONTYPE_H
#define MINIONTYPE_H

#include <string>

#include "fromjson.h"

struct MinionType {
  std::string name;
  std::string baseHP;
  std::string startingLevel;
  std::string startingExps;
  MinionType(){};
  MinionType(std::string name, std::string hp, std::string lvl,
             std::string exps)
      : name(name), baseHP(hp), startingLevel(lvl), startingExps(exps){};

  MinionType(const MinionType& mType) {
    name = mType.name;
    baseHP = mType.baseHP;
    startingLevel = mType.startingLevel;
    startingExps = mType.startingExps;
  }

  constexpr static auto properties = std::make_tuple(
      Property<MinionType, std::string>{&MinionType::name, "name"},
      Property<MinionType, std::string>{&MinionType::baseHP, "baseHP"},
      Property<MinionType, std::string>{&MinionType::startingLevel,
                                        "startingLevel"},
      Property<MinionType, std::string>{&MinionType::startingExps,
                                        "startingExps"});
};

#endif  //? MINIONTYPE_H
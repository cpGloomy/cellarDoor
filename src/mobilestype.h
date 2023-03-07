#ifndef MOBILESTYPE_H
#define MOBILESTYPE_H

#include <string>

#include "fromjson.h"

struct MobilesType {
  std::string name;
  std::string baseHP;
  std::string startingLevel;
  std::string startingExps;
  MobilesType(){};
  MobilesType(std::string name, std::string hp, std::string lvl,
              std::string exps)
      : name(name), baseHP(hp), startingLevel(lvl), startingExps(exps){};

  MobilesType(const MobilesType& mType) {
    name = mType.name;
    baseHP = mType.baseHP;
    startingLevel = mType.startingLevel;
    startingExps = mType.startingExps;
  }

  constexpr static auto properties = std::make_tuple(
      Property<MobilesType, std::string>{&MobilesType::name, "name"},
      Property<MobilesType, std::string>{&MobilesType::baseHP, "baseHP"},
      Property<MobilesType, std::string>{&MobilesType::startingLevel,
                                         "startingLevel"},
      Property<MobilesType, std::string>{&MobilesType::startingExps,
                                         "startingExps"});
};

#endif  //? MOBILESTYPE_H
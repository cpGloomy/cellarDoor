#ifndef MOBILESTYPE_H
#define MOBILESTYPE_H

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <string>

class MobilesType {
 private:
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive &ar, const unsigned int version) {
    ar &name;
    ar &baseHP;
    ar &startingLevel;
    ar &startingExps;
  }

  std::string name;
  int baseHP;
  int startingLevel;
  int startingExps;

 public:
  MobilesType(){};
  MobilesType(std::string name, int hp, int lvl, int exps)
      : name(name), baseHP(hp), startingLevel(lvl), startingExps(exps) {}

  MobilesType(const MobilesType &mType) {
    name = mType.name;
    baseHP = mType.baseHP;
    startingLevel = mType.startingLevel;
    startingExps = mType.startingExps;
  }

  std::string GetName() { return this->name; }
  int GetHP() { return this->baseHP; }
  int GetLevel() { return this->startingLevel; }
  int GetExp() { return this->startingExps; }
};

#endif  //? MOBILESTYPE_H
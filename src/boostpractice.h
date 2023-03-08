#ifndef BOOSTPRACTICE_H
#define BOOSTPRACTICE_H

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
#include <iostream>
#include <string>

class mobilestypeBoost {
 private:
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& name;
    ar& baseHP;
    ar& startingLevel;
    ar& startingExps;
  }

  std::string name;
  int baseHP;
  int startingLevel;
  int startingExps;

 public:
  mobilestypeBoost(){};
  mobilestypeBoost(std::string n_, int hp_, int lvl_, int exp_)
      : name(n_), baseHP(hp_), startingLevel(lvl_), startingExps(exp_) {}
  std::string GetName() { return this->name; }
  int GetHP() { return this->baseHP; }
  int GetLevel() { return this->startingLevel; }
  int GetExp() { return this->startingExps; }
};

#endif  //? BOOSTPRACTICE_H
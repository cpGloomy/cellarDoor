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
    ar &name_;
    ar &base_hp_;
    ar &starting_level_;
    ar &starting_exps_;
    ar &base_min_damage_;
    ar &base_max_damage_;
    ar &base_weapon_skill_;
    ar &base_accuracy_;
    ar &base_evasion_;
  }

  std::string name_;
  int base_hp_;
  int starting_level_;
  int starting_exps_;
  int base_min_damage_;
  int base_max_damage_;
  int base_weapon_skill_;
  int base_accuracy_;
  int base_evasion_;

 public:
  MobilesType(){};
  MobilesType(std::string name_, int hp, int lvl, int exps, int mindmg,
              int maxdmg, int wskill, int acc, int eva)
      : name_(name_),
        base_hp_(hp),
        starting_level_(lvl),
        starting_exps_(exps),
        base_min_damage_(mindmg),
        base_max_damage_(maxdmg),
        base_weapon_skill_(wskill),
        base_accuracy_(acc),
        base_evasion_(eva) {}

  MobilesType(const MobilesType &mType) {
    name_ = mType.name_;
    base_hp_ = mType.base_hp_;
    starting_level_ = mType.starting_level_;
    starting_exps_ = mType.starting_exps_;
    base_min_damage_ = mType.base_min_damage_;
    base_max_damage_ = mType.base_max_damage_;
    base_weapon_skill_ = mType.base_weapon_skill_;
    base_accuracy_ = mType.base_accuracy_;
    base_evasion_ = mType.base_evasion_;
  }

  std::string GetName() { return this->name_; }
  int GetHP() { return this->base_hp_; }
  int GetLevel() { return this->starting_level_; }
  int GetExp() { return this->starting_exps_; }
  int GetMinDamage() { return base_min_damage_; }
  int GetMaxDamage() { return base_max_damage_; }
  int GetWeaponSkill() { return base_weapon_skill_; }
  int GetAccuracy() { return base_accuracy_; }
  int GetEvasion() { return base_evasion_; }
};

#endif  //? MOBILESTYPE_H
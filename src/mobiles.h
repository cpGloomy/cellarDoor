#ifndef MOBILE_H
#define MOBILE_H

#include <string>

struct OffensiveStats {
  int WeaponSkill = 75;
  int Damage = 20;
};

class Mobiles {
 public:
  Mobiles(){};

  virtual ~Mobiles() = default;

  virtual std::string const GetName() = 0;
  virtual void SetName(std::string name) = 0;
  virtual bool IsAlive() = 0;
};

class Combatant {
 public:
  Combatant(Mobiles &combatant) : combatant(combatant){};
  void Attack(Mobiles &defender);
  Mobiles &combatant;

  // virtual void OnHit() = 0;
  // virtual void DealDamage() = 0;
  // virtual void OnTakeHit() = 0;
  // virtual void TakeDamage() = 0;
};

#endif
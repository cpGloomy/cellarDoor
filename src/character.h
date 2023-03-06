#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "mobiles.h"
class Character : public Mobiles {
 public:
  Character(){};
  Character(std::string name) : character_name(name){};

  ~Character(){};

  std::string const GetName() { return character_name; }
  void SetName(std::string name) { character_name = name; }

  bool IsAlive() { return isAlive; }

 private:
  std::string character_name;
  bool isAlive = true;
};

#endif  //? CHARACTER_H
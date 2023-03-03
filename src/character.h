#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
 public:
  Character() : isAlive(true){};
  Character(std::string name) : character_name(name), isAlive(true){};
  ~Character(){};

  std::string const GetName() { return character_name; }
  void SetName(std::string name) { character_name = name; }
  bool IsAlive() { return isAlive; }

 private:
  std::string character_name;
  bool isAlive;
};

#endif  //? CHARACTER_H
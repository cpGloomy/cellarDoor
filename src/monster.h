#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {
 public:
  Monster() : isAlive(true){};
  Monster(std::string name) : name(name), isAlive(true){};

  std::string const GetName() { return name; }
  void SetName(std::string name) { this->name = name; }
  bool IsAlive() { return isAlive; }

 private:
  std::string name;
  bool isAlive;
};
#endif  //? MONSTER_H
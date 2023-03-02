#include <string>

class Character {
 public:
  Character(){};
  ~Character(){};
  std::string GetName() { return character_name; }
  void setName(std::string name) { character_name = name; }

 private:
  std::string character_name;
};
#include <string>

enum TEXTColour {
  BLACK = 30,
  RED = 31,
  GREEN = 32,
  YELLOW = 93,
  BLUE = 34,
  MAGENTA = 35,
  CYAN = 36,
  WHITE = 37
};

class ThisTime {
 public:
  ThisTime(){};
  ~ThisTime(){};
  std::string Get();
};

class ANSIColour {
 public:
  ANSIColour(){};
  ~ANSIColour(){};
  std::string Colour(std::string cs, TEXTColour);
};
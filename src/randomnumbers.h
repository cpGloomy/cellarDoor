#ifndef RANDOMNUMBERS_H
#define RANDOMNUMBERS_H

#include <mutex>
#include <random>

class RandomNumbers {
 private:
  static RandomNumbers *pinstance_;
  static std::mutex mutex_;

  std::random_device rd;

 protected:
  RandomNumbers(){};
  ~RandomNumbers(){};

 public:
  RandomNumbers(RandomNumbers &other) = delete;
  void operator=(const RandomNumbers &) = delete;
  static RandomNumbers *GetInstance();

  int Roll(const int min, const int max);
};

#endif  //? RANDOMNUMBERS_H
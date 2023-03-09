#include "randomnumbers.h"

RandomNumbers* RandomNumbers::pinstance_{nullptr};
std::mutex RandomNumbers::mutex_;

RandomNumbers* RandomNumbers::GetInstance() {
  std::lock_guard<std::mutex> lock(mutex_);
  if (pinstance_ == nullptr) {
    pinstance_ = new RandomNumbers();
  }
  return pinstance_;
}

int RandomNumbers::Roll(const int min, const int max) {
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(min, max);
  return dis(gen);
}
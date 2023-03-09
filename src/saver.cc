#include "saver.h"

Saver *Saver::pinstance_{nullptr};
std::mutex Saver::mutex_;

Saver *Saver::GetInstance() {
  std::lock_guard<std::mutex> lock(mutex_);
  if (pinstance_ == nullptr) {
    pinstance_ = new Saver();
  }
  return pinstance_;
}
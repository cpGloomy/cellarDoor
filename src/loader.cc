#include "loader.h"

Loader* Loader::pinstance_{nullptr};
std::mutex Loader::mutex_;

Loader* Loader::GetInstance() {
  std::lock_guard<std::mutex> lock(mutex_);
  if (pinstance_ == nullptr) {
    pinstance_ = new Loader();
  }
  return pinstance_;
}
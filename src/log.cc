#include "log.h"

std::shared_ptr<spdlog::logger> Log::logger_;

void Log::Init() {
  if (!logger_) {
    spdlog::set_pattern("[%D %T] [%l] %n: %v");
    logger_ = spdlog::basic_logger_mt("CellarDoor", "./logs/cdoorLogger.log");
    logger_->set_level(spdlog::level::trace);
  }
}
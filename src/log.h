#ifndef LOG_H
#define LOG_H

#include <memory>

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

class Log {
 public:
  static void Init();

  inline static std::shared_ptr<spdlog::logger> &GetLogger() { return logger_; }

 private:
  static std::shared_ptr<spdlog::logger> logger_;
};

// log macros
#define LOG_TRACE(...) ::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...) ::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) ::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::Log::GetLogger()->critical(__VA_ARGS__)

#endif  //? LOG_H
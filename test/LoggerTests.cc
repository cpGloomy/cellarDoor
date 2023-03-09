#include <gtest/gtest.h>

#include "../src/log.h"

TEST(LoggerTest, LoggerTests) {
  Log::Init();
  LOG_TRACE("trace");
  LOG_INFO("info");
  LOG_WARN("warning");
  LOG_ERROR("Some error log");
  LOG_CRITICAL("critical");
}
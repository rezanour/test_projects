#pragma once

#include <stdint.h>

namespace test_projects {
    enum class LogLevel {
        Fatal,
        Error,
        Warning,
        Debug,
        Info
    };
    void LogMessage(LogLevel level, char const *filename, uint32_t line_number, char const *format, ...);
} // namespace test_projects

#define TPLOG(level, format, ...) ::test_projects::LogMessage(test_projects::LogLevel::##level, __FILE__, __LINE__, format, __VA_ARGS__);

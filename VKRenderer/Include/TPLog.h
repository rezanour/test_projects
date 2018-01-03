#pragma once

namespace test_projects {
    void LogMessage(char const *format, ...);
} // namespace test_projects

#define TPLOG(format, ...) ::test_projects::LogMessage(format, __VA_ARGS__);

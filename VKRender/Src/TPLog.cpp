#include <TPLog.h>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

namespace test_projects {
    char const *GetLevelText(LogLevel level) {
        switch (level) {
        case LogLevel::Fatal:   return "Fatal";
        case LogLevel::Error:   return "Error";
        case LogLevel::Warning: return "Warning";
        case LogLevel::Debug:   return "Debug";
        case LogLevel::Info:    return "Info";
        default: assert(false); return "Invalid";
        }
    }

    void LogMessage(LogLevel level, char const *filename, uint32_t line_number, char const *format, ...) {
        (void)level;

        // TODO: fix this
        char full_format[1024]{};
        char message[1024]{};

        sprintf_s(full_format, "%s: %s (%u): ", GetLevelText(level), filename, line_number);
        strcat_s(full_format, format);
        strcat_s(full_format, "\n");

        va_list args;
        va_start(args, format);
        vsprintf_s(message, full_format, args);
        va_end(args);

#ifdef _WIN32
        OutputDebugStringA(message);
#endif
    }
} // namespace test_projects

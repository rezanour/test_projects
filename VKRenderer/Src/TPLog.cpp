#include <TPLog.h>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#include <stdarg.h>
#include <stdio.h>

namespace test_projects {
    void LogMessage(char const *format, ...) {
        // TODO: fix this
        char message[128]{};

        va_list args;
        va_start(args, format);
        vsprintf_s(message, sizeof(message), format, args);
        va_end(args);

#ifdef _WIN32
        OutputDebugStringA(message);
#endif
    }
} // namespace test_projects

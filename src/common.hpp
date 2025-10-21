#ifndef COMMON_HPP_
#define COMMON_HPP_

#include <cstdint>
#include <format>
#include <iostream>
#include <regex>

#include "ansi.h"

///////////////////////////////
////  CLI COLORING

#ifndef MXC_CLI_NO_COLOR
#    define MXC_CLI_FG_GREEN ANSI_ESC ANSI_FG_GREEN ANSI_FIN
#    define MXC_CLI_FG_RED ANSI_ESC ANSI_FG_RED ANSI_FIN
#    define MXC_CLI_FG_YELLOW ANSI_ESC ANSI_FG_YELLOW ANSI_FIN
#    define MXC_CLI_FG_DEFAULT ANSI_ESC ANSI_FG_DEFAULT ANSI_FIN
#else
#    define MXC_CLI_FG_GREEN
#    define MXC_CLI_FG_RED
#    define MXC_CLI_FG_YELLOW
#    define MXC_CLI_FG_DEFAULT
#endif

static inline void strip_ansi(std::string &str) {
    // This regex matches ANSI escape sequences, e.g. "\033[31m", "\x1b[1;32H", etc.
    static const std::regex ansi_pattern(R"(\x1B\[[0-9;]*[A-Za-z])");
    str = std::regex_replace(str, ansi_pattern, "");
}

///////////////////////////////
////  LOGGING

typedef enum { TRACE, INFO, WARN, ERROR, OFF } LogLevel;

class Logger {
   public:
    static inline void set_level(LogLevel level) { s_Level = level; }
    static inline void set_colored(bool colored) { s_Colored = colored; }

    template <typename... Args>
    static inline void trace(const std::format_string<Args...> &fmt, Args &&...args) {
        if (static_cast<int32_t>(s_Level) <= static_cast<int32_t>(LogLevel::TRACE))
            Logger::log(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    static inline void info(const std::format_string<Args...> &fmt, Args &&...args) {
        if (static_cast<int32_t>(s_Level) <= static_cast<int32_t>(LogLevel::INFO))
            Logger::log(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    static inline void warn(const std::format_string<Args...> &fmt, Args &&...args) {
        if (static_cast<int32_t>(s_Level) <= static_cast<int32_t>(LogLevel::WARN))
            Logger::log(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    static inline void error(const std::format_string<Args...> &fmt, Args &&...args) {
        if (static_cast<int32_t>(s_Level) <= static_cast<int32_t>(LogLevel::ERROR))
            Logger::log(fmt, std::forward<Args>(args)...);
    }

   private:
    template <typename... Args>
    static inline void log(const std::format_string<Args...> &fmt, Args &&...args) {
        std::string msg = std::format<Args...>(fmt, std::forward<Args>(args)...);
        if (!s_Colored) strip_ansi(msg);
        std::cout << msg << std::endl;
    }

   private:
    static bool s_Colored;
    static LogLevel s_Level;
};

#endif  // COMMON_HPP_

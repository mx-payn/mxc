#include "common.hpp"
#include "config.h"

int main(int argc, char* argv[]) {
    Logger::set_level(LogLevel::TRACE);

    static constexpr std::string_view colored_msg =
        "Hello!" MXC_CLI_FG_YELLOW " Version:" MXC_CLI_FG_DEFAULT " {}";

    Logger::info(colored_msg, MXC_VERSION);

    Logger::set_colored(false);
    Logger::info(colored_msg, MXC_VERSION);

    return 0;
}

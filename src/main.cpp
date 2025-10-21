#include "common.hpp"
#include "config.h"

int main(int argc, char *argv[]) {
    Logger::set_level(LogLevel::TRACE);
    Logger::info("Hello!" MXC_CLI_FG_YELLOW " Version:" MXC_CLI_FG_DEFAULT " {}", MXC_VERSION);

    return 0;
}

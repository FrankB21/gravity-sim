#include <iostream>
#include <string>

#include "spdlog/spdlog.h"

int main()
{
    auto logger = spdlog::default_logger();
    logger->info("Logger initialized!");
}
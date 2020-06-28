// Copyright 2020 Franco Berni

// Licensed under the Apache License, Version 2.0(the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "spdlog/spdlog.h"
#include "glm.hpp"

#include "DisplayManager.hpp"
#include "Config.hpp"

int main()
{
    auto logger = spdlog::default_logger();
    logger->info("Logger initialized!");

    const auto videoMode = sf::VideoMode::getDesktopMode();

    DisplayManager manager(videoMode,
        Config::WIN_TITLE,
        Config::IS_FULLSCREEN,
        Config::getContextSettings());
    logger->info("Created DisplayManager");
    logger->trace(R"(
        DisplayManager:
        Mode:       {}, {}
        AA:         {}
        GL Version  {}.{}
        )",
        videoMode.width,
        videoMode.height,
        Config::getContextSettings().antialiasingLevel,
        Config::getContextSettings().majorVersion,
        Config::getContextSettings().minorVersion);

    while (manager.isOpen())
    {
        manager.pollEvents();
        logger->trace("Polled events");

        manager.clear();
        logger->trace("Cleared screen");
        manager.render();
        logger->trace("Rendered screen");
    }

    return 0;
}

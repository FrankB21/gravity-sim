// Copyright 2020 Franco Berni

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <SFML/Graphics.hpp>

#include "DisplayManager.hpp"


DisplayManager::DisplayManager(const sf::VideoMode &videoMode,
    const std::string &                             title,
    bool                                            fullscreen,
    const sf::ContextSettings &                     settings)
    : m_Window(videoMode,
        title,
        (fullscreen) ? sf::Style::Fullscreen : sf::Style::Default,
        settings)
{
    m_Window.setVerticalSyncEnabled(true);
}

void DisplayManager::pollEvents()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) m_Window.close();
    }
}

void DisplayManager::render()
{
    sf::CircleShape circ(100, 180);
    circ.setFillColor(sf::Color(120, 30, 200));
    m_Window.draw(circ);
    m_Window.display();
}

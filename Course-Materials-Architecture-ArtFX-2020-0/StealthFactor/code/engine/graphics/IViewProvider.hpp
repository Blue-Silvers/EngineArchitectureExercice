#pragma once

#include <SFML/System/Vector2.hpp>

namespace engine
{
    namespace graphics
    {
        class IViewProvider
        {
        public:
            virtual ~IViewProvider() = default;

            virtual sf::Vector2f getViewCenter() const = 0;
        };
    }
}
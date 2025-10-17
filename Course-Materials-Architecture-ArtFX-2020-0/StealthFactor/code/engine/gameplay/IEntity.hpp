#pragma once
#include <string>
#include <vector>
#include <memory>

namespace engine
{
    namespace gameplay
    {
        class Components;

        class IEntity
        {
        public:
            virtual ~IEntity() = default;

            virtual void setPosition(float x = 0.f, float y = 0.f) = 0;
            virtual void setRotation(float angle) = 0;
            virtual void getPosition(float& x, float& y) const = 0;
            virtual float getRotation() const = 0;

            virtual const std::vector<std::unique_ptr<Components>>& GetAllComponent() const = 0;
        };
    }
}
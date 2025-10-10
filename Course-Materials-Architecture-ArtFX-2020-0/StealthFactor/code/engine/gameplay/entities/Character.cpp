#include "Character.hpp"

#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Character::Character()
			{
			}

			Character::~Character()
			{
			}

			void Character::draw()
			{
				graphics::Manager::getInstance().draw(shapeList, getTransform());
			}
		}
	}
}

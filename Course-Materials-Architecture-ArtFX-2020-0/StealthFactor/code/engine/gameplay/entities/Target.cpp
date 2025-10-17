#include "Target.hpp"

#include <engine/graphics/GraphicsManager.hpp>
#include <engine/gameplay/components/ColliderC.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Target::Target()
			{
				shapeList.load("target");

				AddComponent<ColliderC>(1, false);

			}

			Target::~Target()
			{
			}

			void Target::update()
			{
				for (auto& component : GetAllComponent())
				{
					component->Update();
				}
			}

			void Target::draw()
			{
				graphics::Manager::getInstance().draw(shapeList, getTransform());
			}
		}
	}
}

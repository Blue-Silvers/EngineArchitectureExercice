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

				AddComponent(new ColliderC(this, 1, false));
			}

			Target::~Target()
			{
			}

			void Target::update()
			{
				for (Components* components : GetAllComponent())
				{
					components->Update();
				}
			}

			void Target::draw()
			{
				graphics::Manager::getInstance().draw(shapeList, getTransform());
			}
		}
	}
}

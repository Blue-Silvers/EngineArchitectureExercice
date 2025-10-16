#include "Target.hpp"

#include <engine/graphics/GraphicsManager.hpp>
//#include <engine/gameplay/components/ColliderC.hpp>/**/

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Target::Target()
			{
				shapeList.load("target");

				collider = AddComponent<ColliderC>(static_cast<IEntity*>(this), 1, false);

				/*for (auto& component : GetAllComponent())
				{
					if (auto* collider = dynamic_cast<ColliderC*>(component.get()))
					{
						collider->Activate(false);
					}
				}*/
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

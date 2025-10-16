#include "MovingC.hpp"

//#include <engine/gameplay/Entity.hpp>/**/
#include <engine/input/InputManager.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/components/ColliderC.hpp>
#include <ode/collision.h>

namespace engine
{
	namespace gameplay
	{

		MovingC::MovingC(IEntity* pOwner, int updateOrder, bool active) : Components(pOwner, updateOrder, active)
		{
		}
		void MovingC::Update()
		{
			justMoved = false;

			float x, y, z;
			mOwner->getPosition(x, y, z);
			float rotation = mOwner->getRotation();

			if (input::Manager::getInstance().isKeyJustPressed(sf::Keyboard::Left))
			{
				justMoved = true;
				x -= gameplay::Manager::CELL_SIZE;
				rotation = 180.f;
			}

			if (input::Manager::getInstance().isKeyJustPressed(sf::Keyboard::Right))
			{
				justMoved = true;
				x += gameplay::Manager::CELL_SIZE;
				rotation = 0.f;
			}

			if (input::Manager::getInstance().isKeyJustPressed(sf::Keyboard::Up))
			{
				justMoved = true;
				y -= gameplay::Manager::CELL_SIZE;
				rotation = -90.f;
			}

			if (input::Manager::getInstance().isKeyJustPressed(sf::Keyboard::Down))
			{
				justMoved = true;
				y += gameplay::Manager::CELL_SIZE;
				rotation = 90.f;
			}

			if (justMoved)
			{
				mOwner->setPosition(x, y, z);
				mOwner->setRotation(rotation);

				for (auto& component : mOwner->GetAllComponent())
				{
					if (auto* boxCollider = dynamic_cast<ColliderC*>(component.get()))
					{
						dGeomSetPosition(boxCollider->GetCollisionGeomId(), x, y, z);
					}
				}
			}

		}


			bool MovingC::hasJustMoved() const
		{
			return justMoved;
		}
	}
}

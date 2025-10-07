#include "MovingC.hpp"

#include <engine/gameplay/Entity.hpp>
#include <engine/input/InputManager.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/components/ColliderC.hpp>
#include <ode/collision.h>

namespace engine
{
	namespace gameplay
	{
			void MovingC::Update()
			{
				justMoved = false;
				auto position = mOwner->getPosition();
				float rotation = mOwner->getRotation();

				if (input::Manager::getInstance().isKeyJustPressed(sf::Keyboard::Left))
				{
					justMoved = true;
					position.x -= gameplay::Manager::CELL_SIZE;
					rotation = 180.f;
				}

				if (input::Manager::getInstance().isKeyJustPressed(sf::Keyboard::Right))
				{
					justMoved = true;
					position.x += gameplay::Manager::CELL_SIZE;
					rotation = 0.f;
				}

				if (input::Manager::getInstance().isKeyJustPressed(sf::Keyboard::Up))
				{
					justMoved = true;
					position.y -= gameplay::Manager::CELL_SIZE;
					rotation = -90.f;
				}

				if (input::Manager::getInstance().isKeyJustPressed(sf::Keyboard::Down))
				{
					justMoved = true;
					position.y += gameplay::Manager::CELL_SIZE;
					rotation = 90.f;
				}

				if (justMoved)
				{
					mOwner->setPosition(position);
					mOwner->setRotation(rotation);

					for (const auto& component : mOwner->GetAllComponent())
					{
						if (auto* boxCollider = dynamic_cast<ColliderC*>(component.get()))
						{
							dGeomSetPosition(boxCollider->GetCollisionGeomId(), position.x, position.y, 0);
						}
					}
				}
			}

			MovingC::MovingC(std::unique_ptr<Entity> pOwner, int pUpdateOrder) : Components(std::move(pOwner), pUpdateOrder)
			{
			}

			bool MovingC::hasJustMoved() const
			{
				return justMoved;
			}
	}
}

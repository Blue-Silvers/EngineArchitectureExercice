#include "engine/gameplay/entities/Player.hpp"

//#include <ode/collision.h>/**/
//#include <SFML/Graphics/Color.hpp>/**/
//#include <SFML/Graphics/Shape.hpp>/**/
//#include <SFML/Graphics/CircleShape.hpp>/**/
//#include <engine/Engine.hpp>/**/
//
//#include <engine/gameplay/components/ColliderC.hpp>/**/
#include <engine/gameplay/components/MovingC.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Player::Player()
			{
				shapeList.load("player");

				collider = AddComponent<ColliderC>(static_cast<IEntity*>(this));
				AddComponent<MovingC>(this);
			}

			void Player::update()
			{
				for (auto& component : GetAllComponent())
				{
					component->Update();
				}
			}

			bool Player::hasJustMoved() const
			{
				for (auto& component : GetAllComponent())
				{
					if (auto* moving = dynamic_cast<MovingC*>(component.get()))
						return moving->hasJustMoved();
				}
				return false;
			}
		}
	}
}

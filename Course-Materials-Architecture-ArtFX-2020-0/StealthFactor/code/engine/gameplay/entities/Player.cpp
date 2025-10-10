#include "engine/gameplay/entities/Player.hpp"

#include <ode/collision.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <engine/Engine.hpp>
#include <engine/gameplay/components/ColliderC.hpp>
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

				AddComponent(new ColliderC(this, 1));
				AddComponent(new MovingC(this));
			}

			void Player::update()
			{
				for (Components* components : GetAllComponent())
				{
					components->Update();
				}
			}

			bool Player::hasJustMoved() const
			{
				return justMoved;
			}
		}
	}
}

#include <engine/gameplay/Components.hpp>

#include <engine/gameplay/Entity.hpp>

namespace engine
{
	namespace gameplay
	{
		Components::Components(std::unique_ptr<Entity> pOwner) : mOwner(pOwner.get()), mUpdateOrder(1)
		{
		}

		Components::Components(std::unique_ptr<Entity> pOwner, int pUpdateOrder) : mOwner(pOwner.get()), mUpdateOrder(pUpdateOrder)
		{
		}

	}
}
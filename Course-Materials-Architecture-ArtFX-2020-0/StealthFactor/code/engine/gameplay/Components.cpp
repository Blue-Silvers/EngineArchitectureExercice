#include <engine/gameplay/Components.hpp>
#include <engine/gameplay/Entity.hpp>

namespace engine
{
	namespace gameplay
	{
		Components::Components(Entity* pOwner) : mOwner(pOwner), mUpdateOrder(1)
		{
		}

		Components::Components(Entity* pOwner,int pUpdateOrder, bool pActive) : mOwner(pOwner), mUpdateOrder(pUpdateOrder), mIsActive(pActive)
		{
		}

	}
}
#include <engine/gameplay/Components.hpp>

namespace engine
{
	namespace gameplay
	{
		Components::Components(IEntity* pOwner) : mOwner(pOwner), mUpdateOrder(1)
		{
		}

		Components::Components(IEntity* pOwner,int pUpdateOrder, bool pActive) : mOwner(pOwner), mUpdateOrder(pUpdateOrder), mIsActive(pActive)
		{
		}

	}
}
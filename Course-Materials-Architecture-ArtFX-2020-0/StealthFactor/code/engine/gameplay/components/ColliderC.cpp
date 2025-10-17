#include "ColliderC.hpp"

//#include <engine/gameplay/Entity.hpp>/**/
//#include <ode/collision.h>/**/
#include <engine/physics/PhysicsManager.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/entities/Target.hpp>

namespace engine
{
	namespace gameplay
	{
		ColliderC::ColliderC(IEntity* pOwner, int updateOrder, bool active) : Components(pOwner, updateOrder, active)
		{
			collisionGeomId = dCreateBox(physics::Manager::getInstance().getSpaceId(), gameplay::Manager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f, 1.f);
			dGeomSetData(collisionGeomId, this);
		}

		ColliderC::~ColliderC()
		{
			dGeomDestroy(collisionGeomId);
		}

		void ColliderC::Update()
		{
			if (mIsActive == true) 
			{
				auto collisions = physics::Manager::getInstance().getCollisionsWith(collisionGeomId);
				for (auto& geomId : collisions)
				{
					auto entity = reinterpret_cast<ColliderC*>(dGeomGetData(geomId));
					auto targetEntity = dynamic_cast<entities::Target*>(entity->GetOwner());
					if (targetEntity)
					{
						gameplay::Manager::getInstance().loadNextMap();
					}
				}
			}
			else
			{
				float x, y;
				mOwner->getPosition(x, y);
				dGeomSetPosition(collisionGeomId, x, y, 0);
			}
		}

	}
}

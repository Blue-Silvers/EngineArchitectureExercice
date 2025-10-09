#include "ColliderC.hpp"

#include <engine/gameplay/Entity.hpp>
#include <ode/collision.h>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/entities/Target.hpp>

namespace engine
{
	namespace gameplay
	{
		ColliderC::ColliderC(Entity* pOwner, int pUpdateOrder, dGeomID pCollisionGeomId) : Components(pOwner, pUpdateOrder), collisionGeomId(pCollisionGeomId)
		{
			collisionGeomId = pCollisionGeomId;
			collisionGeomId = dCreateBox(physics::Manager::getInstance().getSpaceId(), 0.f, 0.f, 0.f);
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
					auto entity = reinterpret_cast<Entity*>(dGeomGetData(geomId));
					auto targetEntity = dynamic_cast<entities::Target*>(entity);
					if (targetEntity)
					{
						gameplay::Manager::getInstance().loadNextMap();
					}
				}
			}
		}

	}
}

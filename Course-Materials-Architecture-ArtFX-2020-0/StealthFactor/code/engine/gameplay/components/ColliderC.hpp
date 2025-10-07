#pragma once

#include <memory>
#include <ode/collision.h>
#include <engine/gameplay/Components.hpp>

class Entity;

namespace engine
{
	namespace gameplay
	{
		class ColliderC : public Components
		{
		protected:
			dGeomID collisionGeomId;

		public:
			ColliderC(std::unique_ptr<Entity> pOwner, int pUpdateOrder, dGeomID pCollisionGeomId); //Component constructor with owner and default update order
			ColliderC() = delete; //Delete default constructor

			inline dGeomID GetCollisionGeomId() { return collisionGeomId ; }

			void Update() override;
			virtual void OnStart() {};
			virtual void OnEnd() {};
		};
	}
}
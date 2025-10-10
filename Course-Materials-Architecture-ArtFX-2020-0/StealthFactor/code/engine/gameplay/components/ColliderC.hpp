#pragma once

#include <memory>
#include <ode/collision.h>
#include <engine/gameplay/Components.hpp>

namespace engine
{
	namespace gameplay
	{
		class ColliderC : public Components
		{
		protected:
			dGeomID collisionGeomId;

		public:
			ColliderC(Entity* pOwner, int pUpdateOrder, bool pActive = true); //Component constructor with owner and default update order
			~ColliderC();

			inline dGeomID GetCollisionGeomId() { return collisionGeomId ; }

			void Update() override;
			virtual void OnStart() {};
			virtual void OnEnd() {};
		};
	}
}
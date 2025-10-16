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
			ColliderC(IEntity* owner, int updateOrder = 1, bool active = true);//Component constructor with owner and default update order
			~ColliderC();

			inline dGeomID GetCollisionGeomId() { return collisionGeomId ; }

			void SetActive(bool active) { mIsActive = active; }
			bool IsActive() const { return mIsActive; }

			void Update() override;
			virtual void OnStart() {};
			virtual void OnEnd() {};
		};
	}
}
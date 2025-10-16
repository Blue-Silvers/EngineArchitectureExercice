#pragma once
#include "engine/gameplay/IEntity.hpp"

namespace engine
{
	namespace gameplay
	{
		class Components
		{
		protected:
			bool mIsActive{ true };
			IEntity* mOwner = nullptr;
			int mUpdateOrder;

		public:
			Components(IEntity* pOwner);
			Components(IEntity* pOwner, int pUpdateOrder, bool pActive = true); //Component constructor with owner and default update order
			virtual ~Components() = default;

			inline bool Activate(bool pIsActive) { mIsActive = pIsActive ; }
			inline IEntity* GetOwner() { return mOwner; }
			virtual void OnStart() = 0;
			virtual void Update() = 0;
			virtual void OnEnd() = 0;
		};
	}
}
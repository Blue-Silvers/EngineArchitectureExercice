#pragma once

#include <memory>

class Entity;

namespace engine
{
	namespace gameplay
	{
		class Components
		{
		protected:
			bool mIsActive{ true };
			std::unique_ptr<Entity> mOwner;
			int mUpdateOrder;

		public:
			Components(std::unique_ptr<Entity> pOwner);
			Components(std::unique_ptr<Entity> pOwner, int pUpdateOrder); //Component constructor with owner and default update order
			Components() = delete; //Delete default constructor
			inline bool Activate(bool pIsActive) { mIsActive = pIsActive ; }
			virtual void OnStart() = 0;
			virtual void Update() = 0;
			virtual void OnEnd() = 0;
		};
	}
}
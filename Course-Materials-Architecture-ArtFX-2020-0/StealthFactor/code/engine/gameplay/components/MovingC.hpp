#pragma once

#include <memory>
#include <engine/gameplay/Components.hpp>

namespace engine
{
	namespace gameplay
	{
		class MovingC : public Components
		{
		protected:
			bool justMoved{ false };

		public:
			MovingC(IEntity* pOwner, int updateOrder = 1, bool active = true); //Component constructor with owner and default update order

			bool hasJustMoved() const;

			void Update() override;
			virtual void OnStart() {};
			virtual void OnEnd() {};
		};
	}
}
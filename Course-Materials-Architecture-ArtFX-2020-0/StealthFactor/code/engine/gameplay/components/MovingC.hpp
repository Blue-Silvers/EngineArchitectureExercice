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
			MovingC(Entity* pOwner, int pUpdateOrder = 100); //Component constructor with owner and default update order

			bool hasJustMoved() const;

			void Update() override;
			virtual void OnStart() {};
			virtual void OnEnd() {};
		};
	}
}
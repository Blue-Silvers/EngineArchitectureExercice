#pragma once

#include <memory>
#include <engine/gameplay/Components.hpp>

class Entity;

namespace engine
{
	namespace gameplay
	{
		class MovingC : public Components
		{
		protected:
			bool justMoved{ false };

		public:
			MovingC(std::unique_ptr<Entity> pOwner, int pUpdateOrder = 100); //Component constructor with owner and default update order
			MovingC() = delete; //Delete default constructor

			bool hasJustMoved() const;

			void Update() override;
			virtual void OnStart() {};
			virtual void OnEnd() {};
		};
	}
}
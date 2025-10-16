#pragma once

#include <engine/gameplay/entities/Character.hpp>
#include <engine/gameplay/components/ColliderC.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Player : public Character
			{
			public:
				Player();

				virtual void update() override;

				bool hasJustMoved() const;

			private:
				bool justMoved{ false };
				ColliderC* collider = nullptr;
			};
		}
	}
}

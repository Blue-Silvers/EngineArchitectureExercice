#pragma once

#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/Entity.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Character : public Entity
			{
			public:
				Character();
				virtual ~Character();

				virtual void draw() override;

			protected:
				graphics::ShapeList shapeList;
			};
		}
	}
}

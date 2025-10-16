#pragma once

#include <ode/collision.h>
#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/Entity.hpp>
#include <engine/gameplay/components/ColliderC.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Target : public Entity
			{
			public:
				Target();
				~Target();

				virtual void update() override;

				virtual void draw() override;

			private:
				graphics::ShapeList shapeList;
				dGeomID collisionGeomId;
				ColliderC* collider = nullptr;
			};
		}
	}
}

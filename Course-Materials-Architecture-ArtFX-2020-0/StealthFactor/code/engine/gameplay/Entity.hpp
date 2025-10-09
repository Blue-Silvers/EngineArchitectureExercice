#pragma once

#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics/Transform.hpp>
#include <engine/gameplay/Components.hpp>

namespace engine
{
	namespace gameplay
	{
		class Entity
		{
		public:
			virtual ~Entity() = default;

			virtual void update() = 0;
			virtual void draw() = 0;

			const sf::Vector2f &getPosition() const;
			void setPosition(const sf::Vector2f &newPosition);

			float getRotation() const;
			void setRotation(float newRotation);

			const sf::Transform &getTransform() const;

			virtual void AddComponent(Components* pComponents) //Add new components
			{
				mComponentsList.push_back(pComponents);
			};
			virtual std::vector<Components*> GetAllComponent() //get components
			{
				return mComponentsList;
			};
			virtual void RemoveComponent(size_t index) //Remove one component
			{
				if (index >= 0 && mComponentsList.size() > index)
				{
					mComponentsList.erase(mComponentsList.begin() + index);
				}
			};
			virtual void ClearComponent() //Delette all components
			{
				mComponentsList.clear();
			};

		private:
			sf::Vector2f _position{};
			float _rotation{ 0.f };
			sf::Transform _transform;
			std::vector<Components*> mComponentsList;

			void updateTransform();
		};
	}
}

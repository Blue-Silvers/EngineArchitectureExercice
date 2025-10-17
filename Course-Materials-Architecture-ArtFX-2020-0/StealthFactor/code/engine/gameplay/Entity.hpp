#pragma once

#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics/Transform.hpp>
#include <engine/gameplay/Components.hpp>
#include <engine/gameplay/IEntity.hpp>

namespace engine
{
	namespace gameplay
	{
		class Entity : public IEntity
		{
		public:
			Entity() = default;
			virtual ~Entity() = default;

			virtual void update() = 0;
			virtual void draw() = 0;

			const sf::Vector2f &getPosition() const;
			void setPosition(const sf::Vector2f &newPosition);

			const sf::Transform &getTransform() const;

			template <typename T, typename... Args>
			T* AddComponent(Args&&... args)
			{
				auto component = std::make_unique<T>(this, std::forward<Args>(args)...);
				T* ptr = component.get();
				mComponentsList.push_back(std::move(component));
				return ptr;
			}

			void setPosition(float x =0.f, float y = 0.f) override;
			void setRotation(float angle) override;
			void getPosition(float& x, float& y) const override;
			float getRotation() const override;
			const std::vector<std::unique_ptr<Components>>& GetAllComponent() const override;

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
			std::vector<std::unique_ptr<Components>> mComponentsList;

			void updateTransform();
		};
	}
}

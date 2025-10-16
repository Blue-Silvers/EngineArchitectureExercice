#include "Entity.hpp"

namespace engine
{
	namespace gameplay
	{

		void Entity::setPosition(float x, float y, float z)
		{
			_position = sf::Vector2f(x, y);
			updateTransform();
		}

		void Entity::setRotation(float angle)
		{
			_rotation = angle;
			updateTransform();
		}

		void Entity::getPosition(float& x, float& y, float& z) const
		{
			x = _position.x;
			y = _position.y;
			z = 0.f;
		}

		const std::vector<std::unique_ptr<Components>>& Entity::GetAllComponent() const
		{
			return mComponentsList;
		}

		const sf::Vector2f & Entity::getPosition() const
		{
			return _position;
		}

		void Entity::setPosition(const sf::Vector2f &newPosition)
		{
			_position = newPosition;
			updateTransform();
		}

		float Entity::getRotation() const
		{
			return _rotation;
		}

		const sf::Transform & Entity::getTransform() const
		{
			return _transform;
		}

		void Entity::updateTransform()
		{
			_transform = sf::Transform::Identity;
			_transform.translate(_position);
			_transform.rotate(_rotation);
		}
	}
}

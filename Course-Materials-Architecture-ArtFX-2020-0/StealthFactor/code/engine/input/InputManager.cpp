#include "engine/input/InputManager.hpp"

#include <iterator>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/Engine.hpp>

namespace engine
{
	namespace input
	{
		std::unique_ptr<Manager> Manager::instance = nullptr;

		bool Manager::isKeyPressed(sf::Keyboard::Key key) const
		{
			if (!graphics::Manager::getInstance().hasFocus())
				return false;

			return sf::Keyboard::isKeyPressed(key);
		}

		bool Manager::isKeyJustPressed(sf::Keyboard::Key key) const
		{
			if (!graphics::Manager::getInstance().hasFocus())
				return false;

			return justPressedKeys.find(key) != std::end(justPressedKeys);
		}

		bool Manager::isKeyJustReleased(sf::Keyboard::Key key) const
		{
			if (!graphics::Manager::getInstance().hasFocus())
				return false;

			return justReleasedKeys.find(key) != std::end(justReleasedKeys);
		}

		void Manager::update()
		{
			input::Manager::getInstance().clear();

			sf::Event event;
			while (graphics::Manager::getInstance().getWindow().pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					Engine::getInstance().exit();
					break;

				case sf::Event::KeyPressed:
					input::Manager::getInstance().onKeyPressed(event.key);
					break;

				case sf::Event::KeyReleased:
					input::Manager::getInstance().onKeyReleased(event.key);
					break;

				default:
					break;
				}
			}
		}

		void Manager::clear()
		{
			justPressedKeys.clear();
			justReleasedKeys.clear();
		}

		void Manager::onKeyPressed(const sf::Event::KeyEvent &event)
		{
			justPressedKeys.insert(event.code);
		}

		void Manager::onKeyReleased(const sf::Event::KeyEvent &event)
		{
			justReleasedKeys.insert(event.code);
		}

		Manager &Manager::getInstance()
		{
			if (!instance)
				instance = std::make_unique<Manager>();

			return *instance;
		}
	}
}

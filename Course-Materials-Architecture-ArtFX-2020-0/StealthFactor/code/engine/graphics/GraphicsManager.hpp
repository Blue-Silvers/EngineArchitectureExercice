#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <engine/graphics/IViewProvider.hpp>

namespace engine
{
	namespace graphics
	{
		class ShapeList;

		class Manager
		{
		private:
			sf::RenderWindow window;

			static const sf::Int16 WINDOW_WIDTH = 800;
			static const sf::Int16 WINDOW_HEIGHT = 600;

			static std::unique_ptr<Manager> instance;

			const IViewProvider* viewProvider = nullptr;

		public:
			Manager();
			~Manager();

			sf::RenderWindow& getWindow() { return window; }

			void clear();
			void draw(const ShapeList &shapeList, const sf::Transform &transform);
			void display();

			bool hasFocus() const;


			static Manager &getInstance();

			void setViewInterface(const IViewProvider* pViewProvider) { viewProvider = pViewProvider; }
		};
	}
}

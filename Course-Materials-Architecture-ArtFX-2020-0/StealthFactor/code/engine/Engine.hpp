#pragma once

#include <string>
#include <memory>

namespace engine
{
	class Engine
	{
	public:
		void loadConfiguration();

		void run();
		float getDeltaTime() const;

		void exit();

		static Engine &getInstance();

	private:
		bool running;
		float deltaTime;

		// Configuration
		std::string startMap;

		static std::unique_ptr<Engine> instance;
	};
}

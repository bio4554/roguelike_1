#include "Engine.hpp"

#include <iostream>
#include <ranges>
#include <libtcod/libtcod.hpp>
#include <SDL2/SDL.h>

#include "EntitySystem.hpp"
#include "PlayerInputSystem.hpp"

namespace cyberrogue
{
	static std::unique_ptr<Engine> mEngine;
	constexpr char PLAYER_ICON = '@';
	constexpr int MAX_FPS = 60;

	Engine::Engine(int width, int height, const std::string& title, int argc, char* argv[])
	: messageBus([=](Message message) -> void
		{
			this->onNotify(message);
		}), graphics(width, height, title, argc, argv, &messageBus), player({width / 2, height / 2}, {"@"})
	{
		isRunning = true;
		frameCount = 0;
		RegisterSystems();
		dynamic_cast<EntitySystem*>(systems[typeid(EntitySystem)])->registerEntity(&player);
		/*std::string mType = "PLAYER_CREATED";
		std::map<std::string, std::string> mData;
		mData["player_id"] = std::to_string(playerId);*/
	}

	Engine::~Engine()
	{
		TCOD_quit();
	}

	void Engine::HandleEvents()
	{
		
	}

	void Engine::RunGame()
	{
		while(isRunning)
		{
#ifdef _DEBUG
			std::cout << "FRAME: " << frameCount << std::endl;
#endif
			graphics.clear();
			HandleEvents(); // handle events
			messageBus.notify(); // empty message queue
			ProcessSystems(); // update all systems
			frameCount++;
		}
	}


	void Engine::onNotify(Message message)
	{
		if (message.getType() == "SDL_QUIT")
			isRunning = false;
	}

	void Engine::RegisterSystems()
	{
		systems[typeid(EntitySystem)] = new EntitySystem(&messageBus);
		systems[typeid(PlayerInputSystem)] = new PlayerInputSystem(&messageBus, &player);

		systems[typeid(Graphics)] = &graphics; // graphics should run last
	}

	void Engine::ProcessSystems()
	{
		for(const auto& system : systems | std::views::values)
		{
			system->update();
		}
	}
}

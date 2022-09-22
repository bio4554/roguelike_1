#include "Engine.hpp"

#include <iostream>
#include <ranges>
#include <libtcod/libtcod.hpp>
#include <SDL2/SDL.h>
#include <chrono>
#include <thread>

#include "EntitySystem.hpp"
#include "PlayerInputSystem.hpp"
#include "World.hpp"

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


		(static_cast<EntitySystem*>(getSystem(typeid(EntitySystem).name())))->registerEntity(&player);
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
		//using namespace std::chrono_literals;
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
			//std::this_thread::sleep_for(2000ms);
		}
	}


	void Engine::onNotify(Message message)
	{
		if (message.getType() == "SDL_QUIT")
			isRunning = false;
	}

	void Engine::RegisterSystems()
	{
		systems.push_back(new PlayerInputSystem(&messageBus, &player));
		systems.push_back(new World(&messageBus, &graphics));
		systems.push_back(new EntitySystem(&messageBus));
		systems.push_back(&graphics); // graphics should run last
	}

	void Engine::ProcessSystems()
	{
		for(const auto& system : systems)
		{
			system->update();
		}

		/*for(int i = 0; i < systems.size(); i++)
		{
			systems[i]->update();
		}*/
	}


	System* Engine::getSystem(std::string serviceType)
	{
		for(auto system : systems)
		{
			if (typeid(*system).name() == serviceType)
				return system;
		}
		return nullptr;
	}

}

#pragma once
#define SDL_MAIN_HANDLED

#include <map>

#include "Position.hpp"
#include <libtcod/libtcod.hpp>
#include <SDL2/SDL.h>

#include <string>
#include <typeindex>

#include "Entity.hpp"
#include "Graphics.hpp"
#include "System.hpp"

namespace cyberrogue
{
	class Engine
	{
	public:
		Engine(int width, int height, const std::string& title, int argc, char* argv[]);
		~Engine();

		void HandleEvents();

		bool IsRunning() const;
		void ProcessSystems();

		void RunGame();
		

	private:
		void RegisterSystems();

		MessageBus messageBus;
		Graphics graphics;
		Entity player;
		SDL_Event event;
		std::map<std::type_index, std::unique_ptr<System>> systems;
	};
}

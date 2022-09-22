#pragma once
#define SDL_MAIN_HANDLED

#include <map>

#include "pos_t.hpp"
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
		void onNotify(Message message);
		System* getSystem(std::string serviceType);

		double frameCount;
		bool isRunning;



		MessageBus messageBus;
		Graphics graphics;
		Entity player;
		SDL_Event event;
		std::vector<System*> systems;
	};
}

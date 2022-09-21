#pragma once
#define SDL_MAIN_HANDLED

#include "Position.hpp"
#include <libtcod/libtcod.hpp>
#include <SDL2/SDL.h>

#include <string>

#include "Entity.hpp"

namespace cyberrogue
{
	class Engine
	{
	public:
		Engine(int width, int height, const std::string& title, int argc, char* argv[]);
		~Engine();

		void HandleEvents();

		bool IsRunning() const;
		void Render();

	private:
		tcod::Console mainConsole;
		tcod::Context mainContext;
		Entity player;
		SDL_Event event;
	};
}
